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
    void ListItems();
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
    private static AdventureEngine adventure = new AdventureEngine();

    static void Main(string[] args)
    {
        Console.WriteLine("Digite ? para ajuda.");
        Console.WriteLine("Digite goal para ver o objetivo atual.");

        while (true)
        {
            Console.Write(CurrentPath() + "> ");

            string line = Console.ReadLine();

            if (line == null)
            {
                break;
            }

            line = line.Trim();

            if (line.Length == 0)
            {
                continue;
            }

            if (line == "?")
            {
                ShowHelp();
                continue;
            }

            if (line == "goal")
            {
                adventure.ShowGoal();
                continue;
            }

            if (line == "exit")
            {
                break;
            }

            Execute(line);
        }
    }

    private static void Execute(string line)
    {
        string[] parts = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        string command = parts[0];
        string name = parts.Length > 1 ? parts[1] : "";

        if (command == "touch")
        {
            if (Touch(name))
            {
                adventure.Record(command, name, CurrentPath());
            }

            return;
        }

        if (command == "rm")
        {
            if (Remove(name))
            {
                adventure.Record(command, name, CurrentPath());
            }

            return;
        }

        if (command == "ls")
        {
            ListFiles();
            adventure.Record(command, name, CurrentPath());
            return;
        }

        if (command == "mkdir")
        {
            if (MakeFolder(name))
            {
                adventure.Record(command, name, CurrentPath());
            }

            return;
        }

        if (command == "cd")
        {
            if (ChangeFolder(name))
            {
                adventure.Record(command, name, CurrentPath());
            }

            return;
        }

        if (command == "rmdir")
        {
            if (RemoveFolder(name))
            {
                adventure.Record(command, name, CurrentPath());
            }

            return;
        }

        if (command == "pwd")
        {
            Console.WriteLine(CurrentPath());
            adventure.Record(command, name, CurrentPath());
            return;
        }

        Console.WriteLine("Comando invalido. Digite ? para ajuda.");
    }

    private static bool Touch(string name)
    {
        if (name.Length == 0)
        {
            Console.WriteLine("Use: touch nome_do_arquivo");
            return false;
        }

        if (currentFolder.Find(name) != null)
        {
            Console.WriteLine("Ja existe um item chamado: " + name);
            return false;
        }

        currentFolder.Add(new TextFile(name));
        Console.WriteLine("Arquivo criado: " + name);
        return true;
    }

    private static bool Remove(string name)
    {
        if (name.Length == 0)
        {
            Console.WriteLine("Use: rm nome_do_arquivo");
            return false;
        }

        if (currentFolder.RemoveFile(name))
        {
            Console.WriteLine("Arquivo removido: " + name);
            return true;
        }

        Console.WriteLine("Arquivo nao encontrado: " + name);
        return false;
    }

    private static void ListFiles()
    {
        currentFolder.ListItems();
    }

    private static bool MakeFolder(string name)
    {
        if (name.Length == 0)
        {
            Console.WriteLine("Use: mkdir nome_do_diretorio");
            return false;
        }

        if (currentFolder.Find(name) != null)
        {
            Console.WriteLine("Ja existe um item chamado: " + name);
            return false;
        }

        currentFolder.Add(new Folder(name, currentFolder));
        Console.WriteLine("Diretorio criado: " + name);
        return true;
    }

    private static bool ChangeFolder(string name)
    {
        IFileSystemItem item;
        Folder folder;

        if (name.Length == 0)
        {
            Console.WriteLine("Use: cd nome_do_diretorio");
            return false;
        }

        if (name == "/")
        {
            currentFolder = root;
            return true;
        }

        if (name == "..")
        {
            if (currentFolder.GetParent() != null)
            {
                currentFolder = currentFolder.GetParent();
            }

            return true;
        }

        item = currentFolder.Find(name);
        folder = item as Folder;

        if (folder == null)
        {
            Console.WriteLine("Diretorio nao encontrado: " + name);
            return false;
        }

        currentFolder = folder;
        return true;
    }

    private static bool RemoveFolder(string name)
    {
        if (name.Length == 0)
        {
            Console.WriteLine("Use: rmdir nome_do_diretorio");
            return false;
        }

        if (currentFolder.RemoveFolder(name))
        {
            Console.WriteLine("Diretorio removido: " + name);
            return true;
        }

        Console.WriteLine("Diretorio nao encontrado: " + name);
        return false;
    }

    private static string CurrentPath()
    {
        Folder folder = currentFolder;
        List<string> parts = new List<string>();
        int index;
        string path = "";

        while (folder != null && folder != root)
        {
            parts.Add(folder.GetName());
            folder = folder.GetParent();
        }

        for (index = parts.Count - 1; index >= 0; index--)
        {
            path = path + "/" + parts[index];
        }

        if (path.Length == 0)
        {
            return "/";
        }

        return path;
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
        Console.WriteLine("goal          mostra o objetivo atual");
        Console.WriteLine("?             mostra esta ajuda");
        Console.WriteLine("exit          encerra");
    }
}
