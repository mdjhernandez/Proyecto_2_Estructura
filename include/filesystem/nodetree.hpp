#include <iostream>
#include <string>
#include "file.hpp"
#include "directory.hpp"

/*
    Lista enlazada que contiene la 
    dirección de memoria de los hijos de
    un nodo padre dentro del árbol
*/
struct NodeList{ 
    NodeTree *node_address = NULL;
    NodeList *next_node = NULL;
};

/*
    Estructura base de cada 
    nodo del árbol n-ario
*/
struct NodeTree
{   
    File file;
    Directory Directory;
    NodeList *node_list = NULL;
};

/*
    Prototipado de las funciones que se 
    implementarán en el nodetree.cpp
*/
void createNode(bool isFile, bool isDirectory, std::string path, std::string name);

void insertNode(NodeTree *&node, bool isFile, bool isDirectory, std::string path, std::string name);

void deleteNode(NodeTree *&node);
