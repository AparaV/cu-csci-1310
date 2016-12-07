#include <iostream>

using namespace std;

//class fraction
class Fraction{

public:
    Fraction(int, int);//ctor
    ~Fraction(){};//dtor
    int getNum();
    int getDen();
    bool friend operator== (Fraction &f1, Fraction &f2);
    bool friend operator< (Fraction &f1, Fraction &f2){
        if( (f1.num * f2.den) < (f2.num * f1.den) ){
            return true;
        }
        return false;
    }
private:
    int num;
    int den;
};

int main(){

    return 0;
}

//Ctor
Fraction::Fraction(int n, int d){
    num = n;
    den = d;
}

int Fraction::getNum(){
    return num;
}

int Fraction::getDen(){
    return den;
}

bool Fraction::operator==(Fraction &f1, Fraction &f2){

    if(f1.getNum() * f2.getDen() == f2.getNum() * f1.getDen()){
        return true;
    }

    return false;
}
