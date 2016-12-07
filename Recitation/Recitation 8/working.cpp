#include <iostream>

using namespace std;

//Base class - Room
class Building{

protected:
    int floors;
    int rooms;
    string address;
public:

    //ctor
    Building(){};
    Building(int f, int r,string a ){
        floors = f;
        rooms = r;
        address = a;
    }

    //features of the building
    void features(){
        cout << "Floors: " << floors << endl;
        cout << "Rooms: " << rooms << endl;
        cout << "Address: " << address << endl;
    }

    //state the function of the building
    void stateFunction(){
        cout << "This is a simple building. It has no particular function. It is pretty much useless" << endl;
    }

};

//Inherited class - School
class School:public Building{
    int students;
    string name;

public:

    //ctor
    School(int f, int r, string a, int s, string n){
        floors = f;
        rooms = r;
        address = a;
        students = s;
        name = n;
    }

    //state name and capacity of school
    void stateName(){
        cout << "Name: " << name << endl << "Capacity: " << students << endl;
    }

    //state function of school - override parent method
    void stateFunction(){
        cout << "This is a school. It is supposed to teach stuff to children." << endl;
    }

};

//Inherited class - Apartment
class Apartment:public Building{
    int homes;
    string name;
public:

    //ctor
    Apartment(int f, int r, string a, int h, string n){
        floors = f;
        rooms = r;
        address = a;
        homes = h;
        name = n;
    }

    //state name
    void stateName(){
        cout << "Name: " << name << endl << "No. of homes: " << homes << endl;
    }

    void stateFunction(){
        cout << "This is an apartment. It houses lots of people giving them shelter." << endl;
    }

};

int main(){

    cout << "Parent Class" << endl;

    Building b(10, 50, "CO");
    b.features();
    b.stateFunction();

    cout << "=====" << endl;

    cout << "Derived Class - 1" << endl;

    School s(5, 50, "CO", 100, "School");
    s.features();
    s.stateName();
    s.stateFunction();

    cout << "=====" << endl;

    cout << "Derived Class - 2" << endl;

    Apartment a(10, 200, "CO", 70, "Apartment");
    a.features();
    a.stateName();
    a.stateFunction();

    return 0;
}
