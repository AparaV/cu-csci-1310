#include <iostream>

using namespace std;

int add(int a, int b){
    return a+b;
}

double divide(double a, double b){
    return a/b;
}

void  printMessage(string msg){
    cout << msg << endl;
}

int main(){
    /*int n;
    cin >> n;
    cout << n << endl;
    cin.ignore(); //ignore the character
    string s;
    getline(cin, s, '\n');
    cout << s << endl;*/

    //strings and chars
    string strA = "10 a b c d e f";
    int x = strA.find('0');
    cout << x << endl;

    //char
    char chra[20] = "hello";
    cout << chra << endl;
    char chrb[] = {'h', 'e', 'l', 'l', 'o'};
    cout << chrb << endl;

    //functions
    int a = 5;
    int b = 11;
    int c = add(a, b);
    cout << c << endl;
    double d = divide(b, a);
    cout << d << endl;
    printMessage(strA);
    return 0;
}
