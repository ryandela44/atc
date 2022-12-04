#include "Logger.h"



Logger::Logger(std::string filename) : filename(filename){

}

std::string Logger::getCurrentDateTime(std::string s) {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	if (s == "now")
		strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
	else if (s == "date")
		strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
	return std::string(buf);
}

void Logger::log(std::string msg, std::string ret) {
	std::string filePath = filename + getCurrentDateTime("date") + ".txt";
	std::string now = getCurrentDateTime("now");
	std::ofstream ofs(filePath.c_str(), std::ios_base::out | std::ios_base::app);
	if (!ret.empty()) {
	ofs << now << '\t' << msg << '\n';
	}
	else {
		ofs << now << '\t' << msg;
	}
	ofs.close();
}
