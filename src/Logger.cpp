#include <iostream>
#include <time.h>
#include "Filesystem.cpp"

class Logger {
public:
    Logger(Filesystem filesystem) : filesystem(filesystem){

    }
    std::string getCurrentDateTime(string s) {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        if (s == "now")
            strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
        else if (s == "date")
            strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
        return string(buf);
    };

    void log(string msg) {
        string filePath = filesystem.get_file_name() + getCurrentDateTime("date") + ".txt";
        string now = getCurrentDateTime("now");
        ofstream ofs(filePath.c_str(), std::ios_base::out | std::ios_base::app);
        ofs << now << '\t' << msg << '\n';
        ofs.close();
    }

private:
    Filesystem filesystem;
};