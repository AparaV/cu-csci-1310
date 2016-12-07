#include <iostream>

#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

using namespace std;
/*in the .h file, define the class, but not what the class does.
In the definition, we say what each of the class methods looks like,
which means we specify the types of the input parameters and the return
value, but we don't include the code that actually does anything*/
class Automobile
{
    public:
        //constructor has three arguments: two strings and an int
        Automobile(string, string, int);
        ~Automobile();
        string getMake();
        void setMake(string); //there's no variable name, only a type
        string getModel();
        void setModel(string); //there's no variable name, only a type
        string getCondition();
        void setCondition(string); //there's no variable name, only a type
        int getYear();
        int getSpeed();
        void setSpeed(int); //make red cars go faster?
        string getColor();
        void setColor(string); //there's no variable name, only a type

    protected:
    private:
        //define the variables here
        //we don't set any values here
        string make;
        string model;
        int year;
        int speed;
        string color;
        string condition;

};

#endif // AUTOMOBILE_H
