#include "Auto.h"

//constructor
Auto::Auto(string mo, string ma, int yy){
    model = mo;
    make = ma;
    year = yy;
}

//destructor
Auto::~Auto(){

}

//returns the model of the automobile
string Auto::getModel(){
    return model;
}

//returns the make of the automobile
string Auto::getMake(){
    return make;
}

//returns the year the automobile was manufactured
int Auto::getYear(){
    return year;
}
