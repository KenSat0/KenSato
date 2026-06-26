using System;

enum AdventureState
{
    CreateCamp,
    EnterCamp,
    CreateMap,
    ListCamp,
    ReturnRoot,
    RemoveCamp,
    Finished
}

class AdventureEngine
{
    private AdventureState state;

    public AdventureEngine()
    {
        state = AdventureState.CreateCamp;
    }

    public void ShowGoal()
    {
        Console.WriteLine(CurrentGoal());
    }

    public void Record(string command, string name, string currentPath)
    {
        AdventureState oldState = state;

        if (state == AdventureState.CreateCamp)
        {
            if (command == "mkdir" && name == "camp")
            {
                state = AdventureState.EnterCamp;
            }
        }
        else if (state == AdventureState.EnterCamp)
        {
            if (command == "cd" && name == "camp" && currentPath == "/camp")
            {
                state = AdventureState.CreateMap;
            }
        }
        else if (state == AdventureState.CreateMap)
        {
            if (command == "touch" && name == "map.txt" && currentPath == "/camp")
            {
                state = AdventureState.ListCamp;
            }
        }
        else if (state == AdventureState.ListCamp)
        {
            if (command == "ls" && currentPath == "/camp")
            {
                state = AdventureState.ReturnRoot;
            }
        }
        else if (state == AdventureState.ReturnRoot)
        {
            if (command == "cd" && (name == ".." || name == "/") && currentPath == "/")
            {
                state = AdventureState.RemoveCamp;
            }
        }
        else if (state == AdventureState.RemoveCamp)
        {
            if (command == "rmdir" && name == "camp" && currentPath == "/")
            {
                state = AdventureState.Finished;
            }
        }

        if (state != oldState)
        {
            Console.WriteLine("Objetivo atualizado.");
            ShowGoal();
        }
    }

    private string CurrentGoal()
    {
        if (state == AdventureState.CreateCamp)
        {
            return "Objetivo: crie o acampamento com: mkdir camp";
        }

        if (state == AdventureState.EnterCamp)
        {
            return "Objetivo: entre no acampamento com: cd camp";
        }

        if (state == AdventureState.CreateMap)
        {
            return "Objetivo: crie o mapa da aventura com: touch map.txt";
        }

        if (state == AdventureState.ListCamp)
        {
            return "Objetivo: confira o conteudo do acampamento com: ls";
        }

        if (state == AdventureState.ReturnRoot)
        {
            return "Objetivo: volte para a raiz com: cd ..";
        }

        if (state == AdventureState.RemoveCamp)
        {
            return "Objetivo: remova o acampamento com: rmdir camp";
        }

        return "Objetivo: aventura concluida.";
    }
}
