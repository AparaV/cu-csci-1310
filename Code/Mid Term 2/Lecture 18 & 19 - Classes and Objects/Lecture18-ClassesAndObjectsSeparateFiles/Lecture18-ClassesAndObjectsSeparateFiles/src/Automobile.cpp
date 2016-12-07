#include "Automobile.h"
#include <iostream>


    /*
    This is the constructor. When you want to create a new Automobile
    object, you call the constructor. This constructor expects the
    make and model as arguments. You can think of this as you've built
    a new car and assigned a make and model. It's a new car, so the
    condition is set to "new".
    */

Automobile::Automobile(std::string ma, std::string mo, int y)
{
    /*The private instance variables are all defined in the
    Automobile.h file. They can be used here in the constructor
    because Automobile knows about them.*/
    make = ma;
    model = mo;
    year = y;
    condition = "new";
    speed = 0;
    color = "blue";
}

/*Free the memory associated with the object. We don't need to
worry about this too much in this course because the object is
destroyed when we exit the program and we have no need to
destroy the object before that.*/
Automobile::~Automobile()
{
    //dtor

}
/*need the type, the class name, and the method in the class */
/*We can access color and speed because they're defined as variables
in the class in the .h file, which is included at the top of this
file. We have to include the .h to let this .cpp file know the
format to expect. Any implementation in this source file has
to match the defined format in the .h file.*/


void Automobile::setSpeed(int s){
    //make red cars go faster, just because
    if(s >= 0){
        if(color == "red"){
            speed = s*2;
        }
        else{
            speed = s;
        }
    }else{
        cout<<"not a valid speed"<<endl;
    }
}

int Automobile::getSpeed(){
    return speed;
}

    /*
    Here is where we control access to the condition. We could
    add code to setCondition to check the value of c. For example,
    maybe the condition could only be "new", "good", "old", "wrecked".
    In setCondition, you could check that c = one of those values and
    only update condition if it is.

    For every private variable in a class, we typically have a method to
    get the value of the variable, and a method to set the value of the
    variable.

    When you set a value, there's nothing to return, so the method is
    a void. When you get a value, you need to return the value of the
    variable. The return type will be the same type as the variable
    type.
    */

void Automobile::setCondition(string c){
    if(c == "new" || c == "used" || c == "wrecked"){
        condition = c;
    }else{
        cout<<"not a valid condition"<<endl;
    }
}

string Automobile::getCondition(){
    return condition;
}

string Automobile::getColor(){
    return color;
}

void Automobile::setColor(string c){
    //could add nsome error handling here to require specific colors
    color = c;
}
