#ifndef HOLIDAY_H
#define HOLIDAY_H

#include "Date.h"

class Holiday:public Date{
    public:
        Holiday(std::string hName, int m, int d, int y);
        ~Holiday();
        void showDate();
    protected:
    private:
        std::string name;
};

#endif // HOLIDAY_H
