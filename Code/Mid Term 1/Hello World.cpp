#include <iostream>
#include <math.h>

using namespace std;

int main(){
    cout << "Hello World" << endl;

    //variables
    //int
    //float, double
    //strings - alphanumeric literal
    //char
    //bool

    int a = 5;
    cout << a << endl;
    int b = 6;
    cout << "b = " << b << endl;

    float c = 3.3;
    double d = 3.3333;

    string x = "4.5";
    string z = "5.5";

    bool y = true;
    cout << y << endl;

    //addition of numbers
    int e = a+b;
    cout << "a + b = " << d << endl;
    string xz = x + z;
    cout << "x + z " << xz << endl;

    //division
    float num1 = b/a;
    cout << num1 << endl;

    //multiplication
    int num2 = b*a;
    cout << num2 << endl;

    //exponents
    int exp = pow(b,2); //from <math.h>
    cout << exp << endl;

    //order of operations
    //()
    //*,/,%
    //+,-

    //modulus
    a = 51;
    b = 23;
    num1 = a%b;
    cout << num1 << endl;

    return 0;
}
