#include "../include/filesystem/nodetree.hpp"

NodeTree *createNode(bool isFile, std::string path, std::string name, std::string content)
{
    NodeTree *new_node = new NodeTree();

    if (isFile)
    {
        new_node->file.file_name = name;
        new_node->file.file_path = path + "/" + name;
        new_node->file.file_content = content;

        if (createFile(new_node->file))
        {
            std::cout << "Archivo creado exitosamente." << std::endl;
        }
        else
        {
            std::cerr << "Error al crear el archivo." << std::endl;
        }

        if (writeFile(new_node->file))
        {
            std::cout << "Contenido escrito exitosamente." << std::endl;
        }
        else
        {
            std::cerr << "Error al escribir en el archivo." << std::endl;
        }
    }
    else
    {
        new_node->directory.directory_name = name;
        new_node->directory.directory_path = path + "/" + name;
    }

    return new_node;
};

NodeTree *findPathChild(std::string path, NodeList *list)
{
    NodeList *list_aux = list;

    if (list_aux == NULL)
    {
        return nullptr;
    }

    while (list_aux != NULL)
    {
        if (path == list_aux->node_address->directory.directory_path)
        {
            return list_aux->node_address;
        }

        if (path == list_aux->node_address->file.file_path)
        {
            return list_aux->node_address;
        }

        list_aux = list_aux->next_node;
    }

    for (NodeList *child = list->node_address->node_list; child != NULL; child = child->next_node)
    {
        NodeTree *result = findPathChild(path, child);
        if (result != nullptr)
        {
            return result;
        }
    }

    return nullptr;
}

void insertNode(NodeTree *&node_tree, bool isFile, std::string path, std::string name, std::string content)
{
    NodeList *list_aux1 = nullptr;
    NodeList *list_aux2 = nullptr;
    NodeTree *node_aux = nullptr;

    if (node_tree == nullptr)
    {
        node_tree = isFile ? createNode(true, path, name, content) : createNode(false, path, name, content);
    }
    else
    {
        if ((node_tree->file.file_path == path || node_tree->directory.directory_path == path) && node_tree->node_list == nullptr)
        {
            NodeList *new_node_list = new NodeList();
            new_node_list->node_address = isFile ? createNode(true, path, name, content) : createNode(false, path, name, content);
            node_tree->node_list = new_node_list;
        }
        else if ((node_tree->file.file_path == path || node_tree->directory.directory_path == path) && node_tree->node_list != nullptr)
        {
            list_aux1 = node_tree->node_list;
            while (list_aux1 != nullptr)
            {
                list_aux2 = list_aux1;
                list_aux1 = list_aux1->next_node;
            }
            NodeList *new_node_list = new NodeList();
            new_node_list->node_address = isFile ? createNode(true, path, name, content) : createNode(false, path, name, content);
            list_aux2->next_node = new_node_list;
            new_node_list->next_node = list_aux1;
        }
        else
        {
            node_aux = findPathChild(path, node_tree->node_list);
            if (node_aux != nullptr)
            {
                NodeList *new_node_list = new NodeList();
                new_node_list->node_address = isFile ? createNode(true, path, name, content) : createNode(false, path, name, content);
                if (!node_aux->node_list)
                {
                    node_aux->node_list = new_node_list;
                }
                else
                {
                    NodeList *last = node_aux->node_list;
                    while (last->next_node)
                    {
                        last = last->next_node;
                    }
                    last->next_node = new_node_list;
                }
            }
            else
            {
                std::cout << "El path = " << path << " no pudo ser encontrado" << std::endl;
            }
        }
    }
};

void deleteNode(NodeTree *&node)
{
}