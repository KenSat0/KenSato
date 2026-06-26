using System;
using System.Collections.Generic;

interface IFileSystemItem
{
    string GetName();
    void Print(string prefix);
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

// Por convencao, muitos exemplos em C# usam a classe Program para concentrar o inicio do programa.
class Program
{
    private static List<IFileSystemItem> files = new List<IFileSystemItem>();

    // O metodo Main e o ponto de entrada: e por aqui que a aplicacao comeca a executar.
    static void Main(string[] args)
    {
        Console.WriteLine("Digite ? para ajuda.");

        while (true)
        {
            Console.Write("> ");

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

            if (line == "exit")
            {
                break;
            }

            Execute(line);
        }
    }

    private static void Execute(string line)
    {
        // Split separa a linha digitada em pedacos, formando um array de strings.
        // O primeiro argumento diz que o separador e o espaco; RemoveEmptyEntries ignora espacos extras.
        string[] parts = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        string command = parts[0];
        string name = parts.Length > 1 ? parts[1] : "";

        if (command == "touch")
        {
            Touch(name);
            return;
        }

        if (command == "rm")
        {
            Remove(name);
            return;
        }

        if (command == "ls")
        {
            ListFiles();
            return;
        }

        Console.WriteLine("Comando invalido. Digite ? para ajuda.");
    }

    private static void Touch(string name)
    {
        if (name.Length == 0)
        {
            Console.WriteLine("Use: touch nome_do_arquivo");
            return;
        }

        if (ContainsFile(name))
        {
            Console.WriteLine("Arquivo ja existe: " + name);
            return;
        }

        files.Add(new TextFile(name));
        Console.WriteLine("Arquivo criado: " + name);
    }

    private static void Remove(string name)
    {
        if (name.Length == 0)
        {
            Console.WriteLine("Use: rm nome_do_arquivo");
            return;
        }

        if (RemoveFile(name))
        {
            Console.WriteLine("Arquivo removido: " + name);
            return;
        }

        Console.WriteLine("Arquivo nao encontrado: " + name);
    }

    private static void ListFiles()
    {
        int index;

        if (files.Count == 0)
        {
            Console.WriteLine("(vazio)");
            return;
        }

        for (index = 0; index < files.Count; index++)
        {
            files[index].Print("");
        }
    }

    private static bool ContainsFile(string name)
    {
        int index;

        for (index = 0; index < files.Count; index++)
        {
            if (files[index].GetName() == name)
            {
                return true;
            }
        }

        return false;
    }

    private static bool RemoveFile(string name)
    {
        int index;

        for (index = 0; index < files.Count; index++)
        {
            if (files[index].GetName() == name)
            {
                files.RemoveAt(index);
                return true;
            }
        }

        return false;
    }

    private static void ShowHelp()
    {
        Console.WriteLine("Comandos:");
        Console.WriteLine("touch <nome>  cria um arquivo");
        Console.WriteLine("rm <nome>     remove um arquivo");
        Console.WriteLine("ls            lista os arquivos");
        Console.WriteLine("?             mostra esta ajuda");
        Console.WriteLine("exit          encerra");
    }
}




