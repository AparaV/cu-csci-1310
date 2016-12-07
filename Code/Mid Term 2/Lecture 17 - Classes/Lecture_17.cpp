#include <iostream>

using namespace std;

class Automobile{

private:
    string make;
    string model;
    string condition;
    int year;
    int speed;
    int topSpeed;
public:
    //constructor
    Automobile(){};

    Automobile(string ma, string mo, int yy){
        make = ma;
        model = mo;
        year = yy;
        condition = "NEW";
        speed = 0;
        topSpeed = 90;
        cout << "Object constructed" << endl;
    }

    string getCondition(){
        return condition;
    }

    void setCondition(string cond){
        if(cond == "NEW" || cond == "USED" || cond == "WRECKED"){
            condition = cond;
        }
        else{
            cout << "Invalid Condition" << endl;
        }
    }

    string getModel(){
        return model;
    }

    void setModel(string mo){
        model = mo;
    }

    string getMake(){
        return make;
    }

    void setMake(string ma){
        make = ma;
    }

    int getSpeed(){
        return speed;
    }

    void setSpeed(int s){
        if(s >= 0 && s <= topSpeed){
            speed = s;
        }
        else{
            cout << "The car cannot travel at the speed of light!" << endl;
        }
    }

    int getTopSpeed(){
        return topSpeed;
    }

    void setTopSpeed(int s){
        if( s >= 0 && s <= 150){
            topSpeed = s;
        }
        else{
            cout << "The car is not capable of going that fast" << endl;
        }
    }

    void accelerate(int acc){
        speed += acc;
    }
};

int main(){

    Automobile car("Some Company", "Some model", 3333);
    cout << car.getCondition() << endl;

    car.setCondition("WRECKED");
    cout << car.getCondition() << endl;

    int speed;
    cout << "Enter speed of car" << endl;
    cin >> speed;
    car.setTopSpeed(speed);

    cout << "Enter speed of car" << endl;
    cin >> speed;
    car.setSpeed(speed);
    cout << car.getSpeed() << endl;

    return 0;
}
