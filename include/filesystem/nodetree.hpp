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

NodeTree *createNode(bool isFile, std::string path, std::string name, std::string content);

NodeTree *findPathChild(std::string path, NodeList *list);

void insertNode(NodeTree *&node, bool isFile, std::string path, std::string name, std::string content);

void deleteNode(NodeTree *&node);
