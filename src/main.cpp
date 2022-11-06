#include <iostream>
#include "DataDisplay.cpp"
#include <vector>

using namespace std;

int main() {
    std::vector <Aircraft> v = {{0,10000, 10000, 10000,200,200,200}};
    Airspace airspace;
    DataDisplay display(v, airspace);
    display.print_borders();
    cout << "Hello World!!!" << endl; // prints Hello World!!!
    return 0;
}
