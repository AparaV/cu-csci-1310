#include <iostream>
/*include the Automobile.h header file in main.cpp to make
functions declared in this file "aware" of the functionality
defined in Automobile.h. We separate the definition of the class
and the implementation of the class into different files. The
definition is in the .h file and the implementation is in the .cpp
file of the same name.*/

/*For a user-defined class, you need "" around the class
name instead of the <> that you use for built-in functionality*/

#include "Automobile.h"
#include "Elevator.h"

using namespace std;

int main()
{
   /* The Automobile class includes three variables that are private to the
    class. This is for
    protection, you want to be able to control access to those variables
    The only way to change those variables should be through a method in
    the class. A method is a function in a class. We can make the method
    public, and then when the user calls the method, we control how the
    private variables are changed.
    The method is visible when you type the . but the variables
    are not.
    */
    Automobile subaru("subaru", "outback", 2010);
    cout<<subaru.getColor()<<endl;

    Automobile prius("toyota", "prius", 2005);
    prius.setSpeed(50);

    /*The subaru and prius are separate instances of Automobile.
    Changing the values for one will not affect the other.*/
    cout<<"subaru speed:"<<subaru.getSpeed()<<endl;
    cout<<"prius speed:"<<prius.getSpeed()<<endl;

    //new Elevator with 10 floors
    Elevator elev1(10, 0, 0);
    //another elevator with 20 floors
    Elevator elev2(20, 0, 0);
    cout<<"elevator 2 moving"<<endl;
    elev2.goDownOneFloor();

    elev2.goUpOneFloor();
    //go all the way to the top
    //elevator 1 only, doesn't change floor of elev2
    cout<<"elevator 1 moving"<<endl;
    while(elev1.goUpOneFloor()){
        cout<<"Now on:"<<elev1.getCurrentFloor()<<endl;
    }
    //go all the way to the bottom
    while(elev1.goDownOneFloor()){
        cout<<"Now on:"<<elev1.getCurrentFloor()<<endl;
    }

    return 0;
}
