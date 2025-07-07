#include <iostream>
#include "../include/filesystem/nodetree.hpp"
using namespace std;

void mostrarArbol(NodeTree *node, int nivel) {
    if (node == nullptr) return;
    // Mostrar nodo actual
    if (node->file.file_path != "") { // Archivo
        cout << string(nivel * 2, ' ') << "[Archivo] " << node->file.file_path << endl;
    } else { // Directorio
        cout << string(nivel * 2, ' ') << "[Directorio] " << node->directory.directory_path << endl;
    }
    // Recorrer lista de hijos
    if (node->node_list != nullptr) {
        NodeList *current = node->node_list;
        while (current != nullptr) {
            mostrarArbol(current->node_address, nivel + 1);
            current = current->next_node;
        }
    }
}

int main(int argc, char const *argv[])
{
    NodeTree *node_tree = nullptr;
    insertNode(node_tree, false, "", "home");
    insertNode(node_tree, false, "/home", "pepito");
    insertNode(node_tree, false, "/home/pepito", "rayo");
    insertNode(node_tree, true, "/home/pepito/rayo", "toro");
    insertNode(node_tree, true, "/home/pepito/rayo", "homl");
    insertNode(node_tree, false, "/home", "royo");

    cout << "Estructura del árbol:" << endl;
    mostrarArbol(node_tree, 0);
    return 0;
}
