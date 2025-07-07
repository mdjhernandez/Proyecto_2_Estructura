#include <iostream>
#include <string>
#include "file.hpp"
#include "directory.hpp"

struct NodeList;

struct NodeTree
{
    File file;
    Directory directory;
    NodeList *node_list = nullptr;
};

struct NodeList
{
    NodeTree *node_address = nullptr;
    NodeList *next_node = nullptr;
};

NodeTree *createNode(bool isFile, std::string path, std::string name);

NodeTree *findPathChild(std::string path, NodeList *list);

void insertNode(NodeTree *&node, bool isFile, std::string path, std::string name);

void deleteNode(NodeTree *&node);
