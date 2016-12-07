#ifndef AUTO_H
#define AUTO_H

#include <iostream>

using std::string;

class Auto
{
    public:
        Auto(string mo, string ma, int yy);
        ~Auto();
        string getMake();
        string getModel();
        int getYear();
    protected:
    private:
        string model;
        string make;
        int year;
};

#endif // AUTO_H
