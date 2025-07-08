#include <string>
#include "../filesystem/nodetree.hpp"

void comandLS(NodeTree *node, int nivel);

void comandCD(NodeTree *node, std::string path);

void comandTouch(NodeTree *node, std::string path, std::string name);

void comandMKDir(NodeTree *node, std::string path, std::string name);

void comandRM(NodeTree *node, std::string path);

void terminalInterface();