/**Dynamic Memory
 **
 */

#include <iostream>

using namespace std;

struct WeatherData{
    int temp;
    int humidity;
};

void modify(WeatherData* wd){
    for(int i = 0; i < 10; ++i){
        wd[i].temp = i;
    }
}

int main(){

    int* a = new int;
    cout << a << endl;

    int len = 10;

    int* arr = new int[len];

    delete a;
    a = NULL;
    delete []arr;
    arr = NULL;

    WeatherData* wd = new WeatherData[10];

    modify(wd);

    for(int i = 0; i < 10000; ++i){
        cout << wd[i].temp << endl;
    }

    cout << "hello" << endl;

    return 0;
}
