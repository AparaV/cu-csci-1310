#include "Holiday.h"

/*Constructor*/
Holiday::Holiday(string name, int m, int d, int y):name(name), Date(m, d, y){

}

/*Destructor*/
Holiday::~Holiday(){}

/*Show Date*/
void Holiday::showDate(){
    cout << name << " ";
    Date::showDate();
}
