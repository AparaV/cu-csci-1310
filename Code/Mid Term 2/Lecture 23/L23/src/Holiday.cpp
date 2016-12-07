#include "Holiday.h"
#include <iostream>
Holiday::Holiday(std::string hName, int m, int d, int y):name(hName), Date(m, d, y){
    //ctor
}

Holiday::~Holiday(){
    //dtor
}

//holiday show date that also shows the name
void Holiday::showDate(){
    std::cout<<name<<"-"<<month<<"/"<<day<<"/"<<year<<std::endl;
}
