#include <iostream>
#include "Date.h"
#include "Holiday.h"

using namespace std;

//compare two dates
//passing objects are memory intensive - pass by reference instead
bool compareDatesTheHardWay(Date& d1, Date& d2){
    if(d1.getDay() == d2.getDay() && d1.getMonth() == d2.getMonth() && d1.getYear() == d2.getYear()){
        return true;
    }
    return false;
}

//friend function - not a member but has access to private/protected members

int main()
{
    Date d(1, 1, 1990);
    d.showDate();
    Date d2("1/2/1990");
    d2.showDate();

    Holiday h("Christmas", 12, 25, 2016);
    h.showDate();

    bool datesEqual = compareDatesTheHardWay(d, d2);
    if(datesEqual == true){
        cout << "equal" << endl;
    }
    if(datesEqual != true){
        cout << "not equal" << endl;
    }

    cout << "Friend function" << endl;
    bool isEqual = compareDates(d, d2);
    if(isEqual == true){
        cout << "equal" << endl;
    }
    if(isEqual == false){
        cout << "not equal" << endl;
    }

    //operator overload
    cout << "Operator Overlord!" << endl;
    if(d == d2){
        cout << "equal" << endl;
    }
    else{
        cout << "not equal" << endl;
    }

    return 0;
}
