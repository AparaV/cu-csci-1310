#include <iostream>
#include <vector>

using namespace std;

int SumofDigits(int num){
    int sum = 0;
    for(int i = 0; i < 9; ++i){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int ProdofDigits(int num){
    int prod = 1;
    for(int i = 0; i < 9; ++i){
        prod *= num % 10;
        num /= 10;
    }
    return prod;
}

int main(){

    for(int i = 111111111; i < 999999999; ++i){
        if(SumofDigits(i) == 45 && ProdofDigits(i) == 362880){
            cout << i << endl;
        }
    }

    return 0;
}
