#include <iostream>

using namespace std;

void myFunction(int* x){
    //update value of x
    cout << "Inside Function" << endl;
    cout << "address x points to" << x << endl;
    *x = 40;
}

void fArray(int a[]){
    for(int i = 0; i < 10; ++i){
        a[i] = i;
    }
}

int main(){
    /*POINTERS*/
    int x = 10;
    int* xPtr = &x;
    cout << x << endl;
    cout << "address of x (&x): " << &x << endl;
    cout << "address of x (xPtr): " << xPtr << endl;
    cout << *xPtr << endl;
    cout << "address of xPtr: " << &xPtr << endl;
    myFunction(xPtr);
    cout << "After Function" << endl;
    cout << *xPtr << endl;
    cout << x << endl;

    int myArray[10];
    fArray(myArray);
    for(int i = 0; i < 10; ++i){
        cout << myArray[i] << endl;
    }
    return 0;
}
