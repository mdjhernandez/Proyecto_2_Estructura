#include "../include/filesystem/file.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

fs::path getOutputPath(const std::string &file_name = "")
{
    fs::path output_dir = "./output";
    if (!fs::exists(output_dir))
    {
        fs::create_directory(output_dir);
    }
    return output_dir / file_name;
}

bool createFile(const File& file) {
    try {
        fs::path full_path = getOutputPath(file.file_name);
        std::ofstream file_stream(full_path);
        return file_stream.is_open();
    } catch (const std::exception& e) {
        std::cerr << "Error al crear el archivo: " << e.what() << std::endl;
        return false;
    }
}

bool writeFile(const File& file) {
    try {
        fs::path full_path = getOutputPath(file.file_name);
        std::ofstream file_stream(full_path);
        if (!file_stream) {
            std::cerr << "Error al abrir el archivo para escritura." << std::endl;
            return false;
        }
        
        file_stream << file.file_content;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error al escribir en el archivo: " << e.what() << std::endl;
        return false;
    }
}

void readFile(const std::string &file_name, File *file)
{
    if (!file) {
        std::cerr << "Error: puntero de archivo nulo." << std::endl;
        return;
    }

    file->file_name = file_name;

    try {
        fs::path full_path = getOutputPath(file_name);
        std::ifstream file_stream(full_path);

        if (file_stream) {
            file->file_content.assign(
                (std::istreambuf_iterator<char>(file_stream)),
                std::istreambuf_iterator<char>());
        } else {
            std::cerr << "Error al abrir el archivo para lectura." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error al leer el archivo: " << e.what() << std::endl;
    }
}

bool deleteFile(const std::string& file_name) {
    try {
        return fs::remove(getOutputPath(file_name));
    } catch (const std::exception& e) {
        std::cerr << "Error al eliminar el archivo: " << e.what() << std::endl;
        return false;
    }
}
