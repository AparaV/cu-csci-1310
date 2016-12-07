#ifndef ELEVATOR_H
#define ELEVATOR_H

/*In this Elevator class, the arguments to the constructor are 3 integers,
current floor, top floor, and bottom floor. The current floor is what will
change in any elevator instance, and we're going to say that we only move
one floor at a time. The logic in those functions is currentFloor+1 and
currentFloor - 1. Notice that the return value for either of them is a bool.
We're just going to change currentFloor and then call getCurrentFloor to
return its value. The return value is used to indicate whether the move up
one floor or down one floor was successful.*/

class Elevator
{
    public:
        Elevator(int, int, int);
        ~Elevator();
        bool goUpOneFloor();
        bool goDownOneFloor();
        int getCurrentFloor();
    protected:
    private:
        int currentFloor;
        int topFloor;
        int bottomFloor;
};

#endif // ELEVATOR_H
