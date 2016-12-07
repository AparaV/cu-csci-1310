#include <iostream>

using namespace std;

//polygon class
class Polygon{
//protected are inherited by derived class
protected:
    int height;
    int width;
public:
    //ctor
    Polygon(){
        cout << "Polygon ctor called" << endl;
    }
    //set values
    void setValues(int h, int w){
        height = h;
        width = w;
    }
    //area
    void area(){
        cout << "Polygon area called" << endl;
    }

};

//rectangle - derived from polygon
class Rectangle:public Polygon{
public:
    //ctor
    Rectangle(){
        cout << "Rectangle ctor called" << endl;
    }
    //area
    int area(){
        cout << "Rectangle area called" << endl;
        return height * width;
    }
};

//triangle - derived from polygon
class Triangle:public Polygon{
public:
    //ctor
    Triangle(){
        cout << "Triangle ctor called" << endl;
    }
    //area
    double area(){
        cout << "Triangle area called" << endl;
        return static_cast<double>(height * width) / 2;
    }
};

//automobile class
class Automobile{
protected:
    string make;
    string model;
    int year;
    string condition;
public:
    //ctor
    Automobile(string ma, string mo, int y, string co){
        make = ma;
        model = mo;
        year = y;
        condition = co;
        cout << "Automobile ctor called" << endl;
    }
};

//truck - derived from automobile
class Truck:public Automobile{
private:
    string cab;
    string bed;
public:
    //ctor
    Truck(string ma, string mo, int y, string co, string ca, string be):Automobile(ma, mo, y, co){
        cab = ca;
        bed = be;
        cout << "Truck ctor called" << endl;
    }
};

//main function begins
int main(){

    Rectangle rect;
    rect.setValues(5, 5);
    cout << "Area of rectangle: " << rect.area() << endl << endl;

    Triangle tri;
    tri.setValues(7,7);
    cout << "Area of triangle: " << tri.area() << endl << endl;;

    Truck tr("Hello", "there", 1963, "OLD", "null", "buy it yourself");

    return 0;
}
