#include <iostream>
#include "DataDisplay.cpp"
#include <vector>

using namespace std;

int main() {
    std::vector <Aircraft> v = {{1,1000, 1000, 1000,200,200,200},
                                {2,2000, 5000, 7000,200,200,200},
                                {3,7000, 9000, 5000,200,200,200}};
    Airspace airspace;
    DataDisplay display(v, airspace);
    display.print_borders();
    cout << "Hello World!!!" << endl; // prints Hello World!!!
    return 0;
}
