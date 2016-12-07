#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date{
    public:
        Date(int m, int d, int y);
        Date(std::string);
        ~Date();
        void showDate();
        int getMonth();
        int getDay();
        int getYear();
        friend bool compareDates(const Date& d1, const Date& d2);
        friend bool operator== (const Date& d1, const Date& d2);
    protected:
        int month;
        int day;
        int year;
    private:
};

#endif // DATE_H
