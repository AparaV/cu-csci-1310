#include "Elevator.h"
#include<iostream>

using namespace std;

Elevator::Elevator(int tf, int cf, int bf)
{
    topFloor = tf;
    currentFloor = cf;
    bottomFloor = bf;
}

Elevator::~Elevator()
{
    //dtor
}

int Elevator::getCurrentFloor(){
    return currentFloor;
}

/*Notice that there's no argument here. I'm going to use
the value of currentFloor in the instance and increase it if
it's < topFloor. We return true if the change was
successful and false if it wasn't. */
bool Elevator::goDownOneFloor(){
    bool success = false;
    if(currentFloor > bottomFloor){
        currentFloor--;
        cout<<"going down"<<endl;
        success = true;
    }else{
        cout<<"elevator already at the bottom floor"<<endl;
    }
    return success;
}

bool Elevator::goUpOneFloor(){
    bool success = false;
    if(currentFloor < topFloor){
        currentFloor++;
        cout<<"going up"<<endl;
        success = true;
    }else{
        cout<<"elevator already at the top floor"<<endl;
    }
    return success;
}
