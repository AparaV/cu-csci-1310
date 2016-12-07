#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using namespace std;

class Array
{
    public:
        Array(int);
        ~Array();
        void printData();//print data
        void appendData(int);//add data to end
        int returnSize();//return the size
        void updateVal(int, int);//update
        void insertVal(int, int);//insert and shift
    protected:
    private:
        int arrayData[30];
        int arraySize = 30;
        int currIndex = 0;
};

#endif // ARRAY_H
