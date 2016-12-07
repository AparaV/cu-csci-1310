#include <iostream>
#include "Auto.h"
#include "Elevator.h"

using namespace std;

int main(){

    Auto car("Model", "Make", 0);
    cout << car.getMake() << endl;
    cout << car.getModel() << endl;
    cout << car.getYear() << endl;

    Elevator elev1(10, 1, 3);

    return 0;
}
