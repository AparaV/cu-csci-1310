#ifndef HOLIDAY_H
#define HOLIDAY_H

#include <iostream>
#include <Date.h>

using namespace std;

class Holiday:public Date{
    public:
        Holiday(string, int, int, int);
        ~Holiday();
        void showDate();
    protected:
    private:
        string name;
};

#endif // HOLIDAY_H
