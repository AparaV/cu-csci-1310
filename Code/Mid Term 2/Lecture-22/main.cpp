#include <iostream>
#include <Date.h>
#include <Holiday.h>

using namespace std;

int main(){

    Date d1(3, 3, 3333);
    d1.showDate();

    Date d2("10/14/2016");
    d2.showDate();

    Holiday sunday("sunday", 10, 16, 2016);
    sunday.showDate();

    return 0;
}
