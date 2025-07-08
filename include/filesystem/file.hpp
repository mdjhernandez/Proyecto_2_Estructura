#include <string>

struct File
{
    std::string file_path = "";
    std::string file_name = "";
    std::string file_content;
};

bool createFile(const File &file);

bool writeFile(const File &file);

void readFile(const std::string &file_name, File *file);

bool deleteFile(const std::string &file_name);