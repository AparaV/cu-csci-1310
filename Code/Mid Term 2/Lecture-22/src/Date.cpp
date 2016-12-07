#include "Date.h"

/*Constructor*/
Date::Date(int m, int d, int y):month(m), date(d), year(y){

}

Date::Date(string s){
    //assume date = "mm/dd/yy"
    stringstream d;
    d << s;
    string temp;
    getline(d, temp, '/');
    month = stoi(temp);
    getline(d, temp, '/');
    date = stoi(temp);
    getline(d, temp);
    year = stoi(temp);
}

/*Destructor*/
Date::~Date(){}

/*Show Date*/
void Date::showDate(){
    cout << month << "-" << date << "-" << year << endl;
}
