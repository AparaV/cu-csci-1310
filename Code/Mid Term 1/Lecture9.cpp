#include <iostream>

using namespace std;

bool deleteElement(int arr[], int val, int used){
    int index = -1;
    for(int i = 0; i < used; ++i){
        if(arr[i] == val){
            index = i;
            break;
        }
    }

    if(index > -1){
        for(int i = index; i < used - 1; i++){
            arr[i] = arr[i+1];
        }
        return true;
    }

    return false;
}

int main(){

    int iSearch[5] = {1, 3, 4, 5};
    int index = 1;
    int iUsed = 4;
    for(int i = 0; i < iUsed; ++i){
        cout << iSearch[i] << endl;
    }

    for(int i = iUsed; i > index; --i){
        iSearch[i] = iSearch[i-1];
    }
    iUsed++;
    iSearch[index] = 2;

    cout << "Added a 2:" << endl;
    for(int i = 0; i < iUsed; ++i){
        cout << iSearch[i] << endl;
    }

    //write a delete function
    //takes array and value to delete
    if(deleteElement(iSearch, 2, iUsed)){
        iUsed--;
        cout << "Deleted a 2:" << endl;
        for(int i = 0; i < iUsed; ++i){
            cout << iSearch[i] << endl;
        }
    }

    return 0;
}
