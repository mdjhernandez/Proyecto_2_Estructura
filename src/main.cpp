#include <iostream>
#include "../include/filesystem/nodetree.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    NodeTree *node_tree = NULL;
    insertNode(node_tree, false, "", "home"); 
    insertNode(node_tree, false, "/home", "pepito");
    insertNode(node_tree, false, "/home", "rayo"); 

    cout<<"Este es el path: "<<node_tree->directory.directory_path<<endl;
    while(node_tree->node_list != NULL){
        cout<<"Este es el path: "<<node_tree->node_list->node_address->directory.directory_path<<endl;
        node_tree->node_list = node_tree->node_list->next_node;
    }

    return 0;
}
