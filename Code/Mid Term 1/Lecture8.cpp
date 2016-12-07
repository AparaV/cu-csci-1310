/*Lecture 8 - Arrays*/

#include <iostream>

using namespace std;

int searchArray(int a[], int length, int value);

int main(){

    //1D array
    int a[10];
    for(int i = 0; i < 10; ++i){
        a[i] = i;
        cout << a[i] << " ";
    }
    cout << endl << endl;

    //2D array
    int b[5][10];
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 10; ++j){
            b[i][j] = i;
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    /*Array Operations: Insert, Search, Delete*/
    //Search
    int arr[6] = {1, 7, 13, 10, 31, 100};
    int arrSearch = 13;
    int arrIndex = -1;
    int arrLength = 6;
    bool found = false;
    int x = 0;
    while( x < arrLength && !found){
        if(arr[x] == arrSearch){
            found = true;
            arrIndex = x;
        }
        ++x;
    }
    if (arrIndex != -1){
        cout << "Value found at index: " << arrIndex << endl;
    }
    else{
        cout << "Not found" << endl;
    }

    //Insertion



    return 0;
}

int searchArray(int a[], int length, int value){
    for(int i = 0; i < length; ++i){
        if(a[i] == value){
            return i;//if found
        }
    }
    return -1;//not found
}
