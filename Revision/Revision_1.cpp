#include <iostream>

using namespace std;

/*Area of Circle*/
double areaCircle(double radius){
    return 3.1415926 * radius * radius;
}

int main(){

    for(int i = 5; i <= 20; ++i){
        cout << "Radius = " << i << "; Area = " << areaCircle(i) << ";" << endl;
    }

    return 0;
}
