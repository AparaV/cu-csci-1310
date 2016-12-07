#ifndef ELEVATOR_H
#define ELEVATOR_H


class Elevator
{
    public:
        Elevator(int top, int bot, int curr);
        ~Elevator();
    protected:
    private:
        int topFloor;
        int botFloor;
        int currFloor;
};

#endif // ELEVATOR_H
