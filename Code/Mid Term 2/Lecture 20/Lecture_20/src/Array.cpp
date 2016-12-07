#include "Array.h"

//Constructor
Array::Array(int initVal){
    for(int i = 0; i < arraySize; ++i){
        arrayData[i] = initVal;
    }
}

//Destructor
Array::~Array(){}

//Print Data
void Array::printData(){
    for(int i = 0; i < currIndex; ++i){
        cout << arrayData[i] << endl;
    }
}

//Append Data
void Array::appendData(int val){
    if(currIndex < arraySize){
        arrayData[currIndex] = val;
        currIndex++;
    }
    else{
        cout << "Array is full." << endl;
    }
}

//Return Size
int Array::returnSize(){
    return currIndex;
}

//Update a value
void Array::updateVal(int index, int val){
    if(index < arraySize){
        arrayData[index] = val;
    }
    else{
        cout << "Invalid Index" << endl;
    }
}

//Insert Value
void Array::insertVal(int index, int val){
    int temp = arrayData[index+1];
    for(int i = currIndex; i >= index; --i){
        arrayData[i] = arrayData[i - 1];
    }
    arrayData[index] = val;
    currIndex++;
}
