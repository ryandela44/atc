#include "Filesystem.h"
    Filesystem::Filesystem() {

    };

    std::vector<std::string> Filesystem::read(std::string filename) {
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

    std::string Filesystem::get_file_name() {
        return filename;
    }
