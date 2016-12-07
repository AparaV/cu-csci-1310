#include <iostream>
using namespace std;

struct crashMe{
    string name;
    int x;
};

int divint(int, int);
void setint(int*, int);

int main(int argc, char *argv[]){

    /*
    An array of char pointers is how C++ presents command line
    arguments. When you enter values on the command line, they are each
    treated as an array of character arrays, and you can index through the
    array and grab the value. To use the value, you need to convert it to
    the appropriate data type for your uses.

    argc is the number of arguments, so you can use that to loop through
    all of them and just print

    argc is set for you when the program runs, you don't need to set it.
    */

    cout << argc << endl;

    for(int i = 0; i < argc; i++){
        cout<<argv[i]<<endl;
    }

    //cout<<argv[0]<<endl;
    //cout<<argv[1]<<endl;


    /*
    //This code is all commented out because it will crash when it runs. We'll talk
    //about how to run the debugger in lecture to debug the errors.

    int x = 5, y = 2;
    cout << divint(x, y);

    x =3; y = 0;
    cout << divint(x, y);
    */

    /*
    int a;
    setint(&a, 10);
    cout << a << endl;

    int* b;
    setint(b, 10);
    cout << *b << endl;
    */

    /*
    crashMe *c = new crashMe[5];
    for(int i = 0; i < 6; i++){
        cout<<c[i].name<<endl;
    }
    */

   return 0;
}

int divint(int a, int b){
   return a / b;
}


void setint(int* ip, int i){
   *ip = i;
}
