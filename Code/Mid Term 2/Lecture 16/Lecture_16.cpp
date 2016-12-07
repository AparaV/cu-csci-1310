#include <iostream>

using namespace std;

//Person
struct Person{
    string name;
    int score;

    //contructor
    Person(){
        name = "NULL";
        score = -1;
    };
    
    Person(string n, int s){
        name = n;
        score = s;
    }
};

//Weather Data
struct WeatherData{
    double temp;
    double humidity;
    double wind;
};

//Team
struct Team{
    string name;
    int wins;
    int loses;
    
    Team(){};
    
    Team(string n, int w, int l){
        name = n;
        wins = w;
        loses = l;
    }
};

int main(){

    Person person1;
    person1.name = "Anon";
    person1.score = 0;

    //call constructor
    Person person2("Anon2", 0);
    
    cout << person1.name << " " << person1.score << endl;
    cout << person2.name << " " << person2.score << endl;
    
    WeatherData day1;
    day1.humidity = 31;
    day1.temp = 32;
    day1.wind = 33;
    
    cout << day1.humidity << endl;
    cout << day1.temp << endl;
    cout << day1.wind << endl;
    
    WeatherData wdArray[10];
    for(int i = 0; i < 10; ++i){
        wdArray[i].humidity = i + 10;
        wdArray[i].temp = i + i;
        wdArray[i].wind = i * i;
    }
    
    for(int i = 0; i < 10; ++i){
        cout << i << endl;
        cout << wdArray[i].humidity << " ";
        cout << wdArray[i].temp << " ";
        cout << wdArray[i].wind << endl;
    }
    
    Team teams[5];
    teams[0] = Team("LA Dodgers", 91, 68);
    teams[1] = Team("San Francisco", 84, 75);
    teams[2] = Team("Colorado", 74, 85);
    teams[3] = Team("San Diego", 68, 91);
    teams[4] = Team("Arizona", 66, 93);
    
    for(int i = 0; i < 5; ++i){
        cout << teams[i].name << " ";
        cout << teams[i].wins << " - ";
        cout << teams[i].loses << endl;
    }
    
    double avg = 0;
    
    for(int i = 0; i < 5; ++i){
        avg += teams[i].wins;
    }
    avg /= 5;
    
    cout << avg << endl;

    return 0;
}
