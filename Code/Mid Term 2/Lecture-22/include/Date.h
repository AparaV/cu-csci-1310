#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <sstream>

using namespace std;

class Date{
    public:
        Date(int, int, int);
        Date(string);
        ~Date();
        void showDate();
    protected:
        int month;
        int date;
        int year;
    private:
};

#endif // DATE_H
