#include <iostream>

using namespace std;

int main(){

    //CONDITIONALS AND LOOPS

    //Conditionals
    int a = 5;
    if (a < 5){
        cout << "a < 5" << endl;
    }
    else if (a > 5){
        cout << "a > 5" << endl;
    }
    else {
        cout << "a = 5" << endl;
    }

    int b = 6;
    if (a == 5 && b == 6){
        cout << "a = 5 and b = 6" << endl;
    }
    if (a > 5 || b == 6){
        cout << "a > 5 or b = 6" << endl;
    }
    //==, >, <, >=, <=, !=

    //Loops
    int i = 0;
    while(i <= 5){
        cout << i << endl;
        i++;
    }

    for (int i = 0; i < 10; ++i){
        cout << i << endl;
    }


    return 0;
}
