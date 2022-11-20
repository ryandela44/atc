#include <filesystem>
#include <iostream>
#include <fstream>
#include <vector>

class Filesystem {
private:
    std::fstream file;
    std::string content;
    std::string tmp;
    std::vector<std::string> lines;
    std::string filename = "console.log";


public:
    Filesystem() {

    };

    std::vector<std::string> read(std::string filename) {
        file.open(filename)
        if (file.is_open()) {
            file >> content;
        }
        for (auto c : content) {
            if (c != '\n') {
                tmp.append(c);
            }
            else {
                lines.push_back(tmp);
                tmp.clear();
            }
        }
        return lines;
    }

    void write() {

    }

    std::string get_file_name() {
        return filename;
    }

};