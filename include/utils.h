#ifndef UTILS_H
#define UTILS_H

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

const auto PATH = fs::current_path();

auto get_path(const std::string& rel) -> std::string 
{
     fs::path result{PATH.c_str()};

    result /= rel; 

    return result.c_str();
}

#endif