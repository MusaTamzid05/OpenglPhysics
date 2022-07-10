#include "utils.h"
#include <fstream>

namespace Utils {
    bool file_exists(std::string& path) {
        std::ifstream input_file(path.c_str());
        return input_file.good();
    }

    std::vector<std::string> split(const std::string &str, char splitter) {
        std::vector<std::string> results;
        std::string temp = "";

        for(char ch : str) {

            if(ch == ' ') {
                results.push_back(temp);
                temp = "";
                continue;
            }

            temp += ch;

        }

        if(temp.size() > 0)
            results.push_back(temp);


        return results;
    }
}
