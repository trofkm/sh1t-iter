#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <vector>

void shit_iterate(std::vector<std::fstream> &files) {
    for (auto &file: files) {
        std::string line;
        std::cout << "iterating over file " << std::endl;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
            // do some shizzy stuff
        }
        file.close();
        std::remove_if(files.begin(), files.end(), [](const std::fstream &f){return f.eof();});

    }
}


int main() {
    std::vector<std::fstream> files;
    files.emplace_back("F:\\Code\\FIles\\files\\1.txt");
    files.emplace_back("F:\\Code\\FIles\\files\\2.txt");
    files.emplace_back("F:\\Code\\FIles\\files\\3.txt");
//    files.emplace_back("F:\\Code\\FIles\\files\\empty.txt");
    shit_iterate(files);
    return 0;
}
