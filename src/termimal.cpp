#include <iostream>
#include <string>
#include "../include/terminal/interface.hpp"

void comandLS(NodeTree *node, int nivel)
{
    if (node == nullptr)
        return;

    if (node->file.file_path != "")
    {
        std::cout << std::string(nivel * 2, ' ') << "[Archivo] " << node->file.file_path << std::endl;
    }
    else
    {
        std::cout << std::string(nivel * 2, ' ') << "[Directorio] " << node->directory.directory_path << std::endl;
    }

    if (node->node_list != nullptr)
    {
        NodeList *current = node->node_list;
        while (current != nullptr)
        {
            if (current->node_address != nullptr)
            {
                if (current->node_address->file.file_path != "")
                {
                    std::cout << std::string((nivel + 1) * 2, ' ') << "[Archivo] " << current->node_address->file.file_path << std::endl;
                }
                else
                {
                    std::cout << std::string((nivel + 1) * 2, ' ') << "[Directorio] " << current->node_address->directory.directory_path << std::endl;
                }
            }
            current = current->next_node;
        }
    }
}

void terminalInterface()
{
    NodeTree *node_tree = nullptr;
    NodeTree *find_node = nullptr;
    insertNode(node_tree, false, "", "home", "");

    std::string current_path = "/home";
    std::string command;
    std::string target_path;
    std::string file_name;
    std::string file_content;
    std::string folder_name;

    do
    {
        std::cout << "\n--- Terminal María Unix ---\n";
        std::cout << "Path actual = " << current_path << std::endl;
        std::cout << "Introduce un comando = ";
        std::cin >> command;

        if (command == "ls")
        {
            std::cout << std::endl;
            std::cout << "Comando 'ls' (listar contenido)\n";
            std::cout << "Introduce el path a listar: ";
            std::cin >> std::ws;
            std::getline(std::cin, target_path);

            if (target_path == "/home")
            {

                std::cout << "Listando contenido de: " << current_path << std::endl;
                std::cout << std::endl;
                comandLS(node_tree, 0);
            }
            else
            {
                find_node = findPathChild(target_path, node_tree->node_list);
                std::cout << "Listando contenido de: " << target_path << std::endl;
                std::cout << std::endl;
                comandLS(find_node, 0);
            }
        }
        else if (command == "cd")
        {
            std::cout << "Funcionalidad no terminada" << std::endl;
        }
        else if (command == "touch")
        {
            std::cout << std::endl;
            std::cout << "Comando 'touch' (crear archivo)\n";
            std::cout << "Introduce el path donde crear el archivo = ";
            std::cin >> std::ws;
            std::getline(std::cin, target_path);

            std::cout << "Introduce el nombre del nuevo archivo = ";
            std::getline(std::cin, file_name);

            std::cout << "Introduce el contenido del archivo = ";
            std::getline(std::cin, file_content);

            if (!target_path.empty() && !file_name.empty())
            {
                std::cout << "Creando archivo '" << file_name << "' en el path: " << target_path << std::endl;
                std::cout << std::endl;
                insertNode(node_tree, true, target_path, file_name, file_content);
            }
            else
            {
                std::cout << "Path o nombre de archivo no pueden estar vacíos." << std::endl;
            }
        }
        else if (command == "mkdir")
        {
            std::cout << std::endl;
            std::cout << "Comando 'mkdir' (crear directorio)\n";
            std::cout << "Introduce el path donde crear el directorio = ";
            std::cin >> std::ws;
            std::getline(std::cin, target_path);

            std::cout << "Introduce el nombre del nuevo directorio = ";
            std::getline(std::cin, folder_name);

            if (!target_path.empty() && !folder_name.empty())
            {
                std::cout << "Creando directorio '" << folder_name << "' en el path: " << target_path << std::endl;
                std::cout << std::endl;
                insertNode(node_tree, false, target_path, folder_name, "");
            }
            else
            {
                std::cout << "Path o nombre de directorio no pueden estar vacíos." << std::endl;
            }
        }
        else if (command == "rm")
        {
            std::cout << "Funcionalidad no terminada" << std::endl;
        }
        else if (command == "exit")
        {
            std::cout << "\nMuchas Gracias por usar la terminal María Unix. ¡Hasta luego!\n";
        }
        else
        {
            std::cout << "\nComando no encontrado: '" << command << "'. Intenta con 'ls', 'cd', 'touch', 'mkdir', 'rm, o 'exit'.\n";
        }

        std::cout << std::endl;

    } while (command != "exit");
}
