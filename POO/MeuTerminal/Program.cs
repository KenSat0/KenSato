using System;
using System.Collections.Generic;

interface IFileSystemItem
{
    string GetName();
    void Print(string prefix);
}

interface IFolder : IFileSystemItem
{
    Folder GetParent();
    void Add(IFileSystemItem item);
    IFileSystemItem Find(string name);
    bool RemoveFile(string name);
    bool RemoveFolder(string name);
    int CountFiles(); // Adicionado ao contrato
}

class TextFile : IFileSystemItem
{
    private string name;

    public TextFile(string fileName)
    {
        name = fileName;
    }

    public string GetName()
    {
        return name;
    }

    public void Print(string prefix)
    {
        Console.WriteLine(prefix + name);
    }
}

class Folder : IFolder
{
    private string name;
    private Folder parent;
    private List<IFileSystemItem> items;

    public Folder(string folderName, Folder parentFolder)
    {
        name = folderName;
        parent = parentFolder;
        items = new List<IFileSystemItem>();
    }

    public string GetName()
    {
        return name;
    }

    public Folder GetParent()
    {
        return parent;
    }

    public void Add(IFileSystemItem item)
    {
        items.Add(item);
    }

    public IFileSystemItem Find(string itemName)
    {
        int index;

        for (index = 0; index < items.Count; index++)
        {
            if (items[index].GetName() == itemName)
            {
                return items[index];
            }
        }

        return null;
    }

    public bool RemoveFile(string itemName)
    {
        int index;

        for (index = 0; index < items.Count; index++)
        {
            if (items[index].GetName() == itemName && items[index] is TextFile)
            {
                items.RemoveAt(index);
                return true;
            }
        }

        return false;
    }

    public bool RemoveFolder(string itemName)
    {
        int index;

        for (index = 0; index < items.Count; index++)
        {
            if (items[index].GetName() == itemName && items[index] is Folder)
            {
                items.RemoveAt(index);
                return true;
            }
        }

        return false;
    }

    // Implementação do novo método de contagem
    public int CountFiles()
    {
        int count = 0;
        foreach (var item in items)
        {
            if (item is TextFile) count++;
        }
        return count;
    }

    public void Print(string prefix)
    {
        Console.WriteLine(prefix + name + "/");
    }

    public void ListItems()
    {
        int index;

        if (items.Count == 0)
        {
            Console.WriteLine("(vazio)");
            return;
        }

        for (index = 0; index < items.Count; index++)
        {
            items[index].Print("");
        }
    }
}

class Program
{
    private static Folder root = new Folder("/", null);
    private static Folder currentFolder = root;

    static void Main(string[] args)
    {
        Console.WriteLine("Digite ? para ajuda.");

        while (true)
        {
            Console.Write(CurrentPath() + "> ");

            string line = Console.ReadLine();

            if (line == null) break;

            line = line.Trim();

            if (line.Length == 0) continue;

            if (line == "?")
            {
                ShowHelp();
                continue;
            }

            if (line == "exit") break;

            Execute(line);
        }
    }

    private static void Execute(string line)
    {
        string[] parts = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        string command = parts[0];
        string name = parts.Length > 1 ? parts[1] : "";

        if (command == "touch") { Touch(name); return; }
        if (command == "rm") { Remove(name); return; }
        if (command == "ls") { ListFiles(); return; }
        if (command == "mkdir") { MakeFolder(name); return; }
        if (command == "cd") { ChangeFolder(name); return; }
        if (command == "rmdir") { RemoveFolder(name); return; }
        if (command == "pwd") { Console.WriteLine(CurrentPath()); return; }
        
        // Novo comando adicionado ao menu
        if (command == "count") { CountFilesCommand(name); return; }

        Console.WriteLine("Comando invalido. Digite ? para ajuda.");
    }

    private static void CountFilesCommand(string name)
    {
        Folder target = currentFolder;
        if (name.Length > 0)
        {
            IFileSystemItem item = currentFolder.Find(name);
            target = item as Folder;
            if (target == null)
            {
                Console.WriteLine("Diretorio nao encontrado: " + name);
                return;
            }
        }
        Console.WriteLine("Total de arquivos em '" + target.GetName() + "': " + target.CountFiles());
    }

    // ... (Mantendo os outros métodos Touch, Remove, ListFiles, etc. inalterados)
    private static void Touch(string name) { if (name.Length > 0) currentFolder.Add(new TextFile(name)); }
    private static void Remove(string name) { currentFolder.RemoveFile(name); }
    private static void ListFiles() { currentFolder.ListItems(); }
    private static void MakeFolder(string name) { if (name.Length > 0) currentFolder.Add(new Folder(name, currentFolder)); }
    private static void ChangeFolder(string name) { 
        if (name == "/") currentFolder = root;
        else if (name == "..") { if (currentFolder.GetParent() != null) currentFolder = currentFolder.GetParent(); }
        else { var f = currentFolder.Find(name) as Folder; if (f != null) currentFolder = f; }
    }
    private static void RemoveFolder(string name) { currentFolder.RemoveFolder(name); }
    private static string CurrentPath() { 
        Folder folder = currentFolder; string path = ""; 
        while (folder != null && folder != root) { path = "/" + folder.GetName() + path; folder = folder.GetParent(); }
        return path == "" ? "/" : path; 
    }

    private static void ShowHelp()
    {
        Console.WriteLine("Comandos:");
        Console.WriteLine("touch <nome>  cria um arquivo");
        Console.WriteLine("rm <nome>     remove um arquivo");
        Console.WriteLine("ls            lista arquivos e diretorios");
        Console.WriteLine("mkdir <nome>  cria um diretorio");
        Console.WriteLine("cd <nome>     entra em um diretorio");
        Console.WriteLine("cd ..         volta um diretorio");
        Console.WriteLine("cd /          volta para a raiz");
        Console.WriteLine("rmdir <nome>  remove um diretorio");
        Console.WriteLine("pwd           mostra o diretorio atual");
        Console.WriteLine("count [nome]  conta arquivos (opcional: pasta)");
        Console.WriteLine("?             mostra esta ajuda");
        Console.WriteLine("exit          encerra");
    }
}