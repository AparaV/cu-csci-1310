#include <iostream>
#include <sstream>

using namespace std;

int a = 6;//global; bad code

#define MPG 20.2 //macro, replace MPG with 20.2
#define MAX(x, y) ((x > y) ? x : y)

const int intConst = 100;//global

void scopeTest(){
    cout << a << endl;
}

int main(){

    int a = 10;//a is local to main
    scopeTest();
    cout << "inside main: " << a << endl;
    a++;
    scopeTest();
    cout << "inside main a++: " << a << endl;

    cout << "MPG: " << MPG << endl;

    cout <<  "MAX(1,2): " << MAX(1, 2) << endl << endl;

    //arrays
    int arr[10];
    for(int i = 0; i < 10; ++i){
        arr[i] = i;
        cout << arr[i] << endl;
    }

    string strArr[10];
    for(int i = 0; i < 10; ++i){
        cout << static_cast<char>(i) << endl;
        strArr[i] = "string" + static_cast<char>(i);
        cout << strArr[i] << endl;
    }

    return 0;
}
