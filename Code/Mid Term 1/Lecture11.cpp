#include <iostream>

using namespace std;

//add two numbers
int add(int a, int b){
    return a + b;
}

//adds two numbers and sets third argument to sum
void add2(int a, int b, int* c){
    *c = a + b;
}

//sum, difference, product
void sum_diff_prod(int a, int b, int* sum, int* diff, int* prod){
    *sum = a + b;
    *diff = a - b;
    *prod = a * b;
}

int main(){

    int a = 5;
    int b = 6;
    int c = add(a, b);
    cout << "First function result: " << c << endl;
    int d;
    add2(a, b, &d);
    cout << "Second function result: " << d << endl;
    int sum, diff, prod;
    sum_diff_prod(a, b, &sum, &diff, &prod);
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << prod << endl;

    return 0;
}
