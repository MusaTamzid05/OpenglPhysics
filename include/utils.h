#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

namespace Utils {
    bool file_exists(std::string& path);
    std::vector<std::string> split(const std::string &str, char splitter);
}

#endif
