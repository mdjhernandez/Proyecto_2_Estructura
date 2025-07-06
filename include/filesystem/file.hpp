#include <string>

struct File{
    std::string file_path = "";
    std::string file_name = "";
};

void createFile();

void writeFile();

void readFile();

void deleteFile();