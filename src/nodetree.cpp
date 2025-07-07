#include "../include/filesystem/nodetree.hpp"

NodeTree *createNode(bool isFile, std::string path, std::string name)
{
    NodeTree *new_node = new NodeTree();

    if (isFile)
    {
        new_node->file.file_name = name;
        new_node->file.file_path = path + "/" + name;
    }
    else
    {
        new_node->directory.directory_name = name;
        new_node->directory.directory_path = path + "/" + name;
    }

    return new_node;
};

void insertNode(NodeTree *&node_tree, bool isFile, std::string path, std::string name)
{
    NodeList *list_aux1 = NULL;
    NodeList *list_aux2 = NULL;

    if (node_tree == NULL)
    {
        node_tree = isFile ? createNode(true, path, name) : createNode(false, path, name);
    }
    else
    {
        if ((node_tree->file.file_path == path || node_tree->directory.directory_path == path) && node_tree->node_list == NULL)
        {
            NodeList *new_node_list = new NodeList();
            new_node_list->node_address = isFile ? createNode(true, path, name) : createNode(false, path, name);
            node_tree->node_list = new_node_list;
        }
        else if ((node_tree->file.file_path == path || node_tree->directory.directory_path == path) && node_tree->node_list != NULL)
        {
            list_aux1 = node_tree->node_list;
            while (list_aux1 != NULL)
            {
                list_aux2 = list_aux1;
                list_aux1 = list_aux1->next_node;
            }
            NodeList *new_node_list = new NodeList();
            new_node_list->node_address = isFile ? createNode(true, path, name) : createNode(false, path, name);
            list_aux2->next_node = new_node_list;
            new_node_list->next_node = list_aux1;
        }
    }
};

void deleteNode(NodeTree *&node)
{
}