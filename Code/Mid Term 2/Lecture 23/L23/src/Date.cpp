#include "Date.h"
#include <iostream>
#include <sstream>
using namespace std;

//member initialization list
Date::Date(int m, int d, int y):month(m), day(d), year(y){
    //ctor
    //!don't need to set month, day, year because they're in initialization
    //month = m;
    //day = d;
    //year = y;
}

Date::Date(string date){
    //assumption that date format is m/d/y
    //convert the string into three ints
    stringstream ss;
    ss<<date;
    string temp;
    //month
    getline(ss, temp, '/');
    month = stoi(temp);
    //day
    getline(ss, temp, '/');
    day = stoi(temp);

    //year
    getline(ss, temp, '/');
    year = stoi(temp);

}

Date::~Date(){
    //dtor
}

void Date::showDate(){
    cout<<month<<"/"<<day<<"/"<<year<<endl;
}

//get day
int Date::getDay(){
    return day;
}

//get month
int Date::getMonth(){
    return month;
}

//get Year
int Date::getYear(){
    return year;
}

//compare dates
bool compareDates(const Date& d1, const Date& d2){
    if(d1.day == d2.day && d1.month == d2.month && d1.year == d2.year){
        return true;
    }
    return false;
}

//compare dates - operator overload
bool operator== (const Date& d1, const Date& d2){
    if(d1.day == d2.day && d1.month == d2.month && d1.year == d2.year){
        return true;
    }
    return false;
}
