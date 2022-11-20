#include <iostream>
#include <time.h>
#include <string>
#include <ostream>
#include "Filesystem.h"

class Logger {
public:
    Logger(Filesystem filesystem) : filesystem(filesystem) {

    }

    std::string getCurrentDateTime(std::string s) {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        if (s == "now")
            strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
        else if (s == "date")
            strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
        return std::string(buf);
    };

    void log(std::string msg) {
//        std::string filePath = filesystem.get_file_name() + getCurrentDateTime("date") + ".txt";
//        std::string now = getCurrentDateTime("now");
//        std::ofstream ofs(filePath.c_str(), std::ios_base::out | std::ios_base::app);
//        ofs << now << '\t' << msg << '\n';
//        ofs.close();
    }

private:
    Filesystem filesystem;
};
