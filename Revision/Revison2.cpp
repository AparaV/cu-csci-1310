#include <iostream>

using namespace std;

//count odd numbers in an array
int countOdds(int a[], int length){
    int counter = 0;
    for(int i = 0; i < length; ++i){
        if(a[i] % 2 == 1){
            counter++;
        }
    }
    return counter;
}

//swap two elements in an array
void swapInt(int a[], int index1, int index2){
    int temp = a[index1];
    a[index1] = a[index2];
    a[index2] = temp;
}

int main(){

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Number of odds: " << countOdds(a, 10);
    swapInt(a, 0, 9);
    cout << "Swapped index 0 and index 9: " << endl;
    for(int i = 0; i < 10; ++i){
        cout << a[i] << endl;
    }

    return 0;
}
