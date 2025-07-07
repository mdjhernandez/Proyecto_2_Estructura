#include <iostream>
#include <string>
#include "file.hpp"
#include "directory.hpp"

struct NodeList;

struct NodeTree
{
    File file;
    Directory directory;
    NodeList *node_list = NULL;
};

struct NodeList
{
    NodeTree *node_address = NULL;
    NodeList *next_node = NULL;
};

NodeTree *createNode(bool isFile, std::string path, std::string name);

void insertNode(NodeTree *&node, bool isFile, std::string path, std::string name);

void deleteNode(NodeTree *&node);
