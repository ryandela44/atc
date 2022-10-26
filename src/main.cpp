#include <iostream>
#include "Airspace.cpp"
#include "Aircraft.cpp"
#include "DataDisplay.cpp"
#include <vector>
using namespace std;

int main() {
    std::vector<Aircraft>() v = {{10000, 10000, 10000}};
    Airspace airspace;
    DataDisplay display(v,airspace);
    display.print_borders();
	cout << "Hello World!!!" << endl; // prints Hello World!!!
	return 0;
}
