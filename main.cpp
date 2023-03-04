#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <vector>

// can miss some elements in case of empty file somewhere in the vector
void shit_iterate(std::vector<std::fstream> &files) {
    for (auto &file: files) {
        std::string line;
        std::cout << "iterating over file " << std::endl;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
            // do some shizzy stuff
        }
        file.close();
        std::ranges::remove_if(files, [](const std::fstream &f) { return f.eof(); });
    }
}

void good_iterate(std::vector<std::fstream> &files) {
    for (auto &file: files) {
        std::string line;
        std::cout << "iterating over file " << std::endl;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
            // do some shizzy stuff
        }
        file.close();
    }
    std::ranges::remove_if(files, [](const std::fstream &f) { return f.eof(); });
}


int main() {
    std::vector<std::fstream> files;
    // try to move around empty file emplace_back
    files.emplace_back(R"(F:\Code\FIles\files\empty.txt)");
    files.emplace_back(R"(F:\Code\FIles\files\1.txt)");
    files.emplace_back(R"(F:\Code\FIles\files\2.txt)");
    files.emplace_back(R"(F:\Code\FIles\files\3.txt)");
    good_iterate(files);
    return 0;
}
