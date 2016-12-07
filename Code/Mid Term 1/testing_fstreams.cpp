#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    char name[20] = "text.txt";

    ifstream infile;
    int n;
    int a[3][3];
    int i = 0;
    int j = 0;

    infile.open(name);

    for(int i = 0 ; i < 3; i++){
        for(int j = 0; j < 3; ++j){
            infile >> a[i][j];
        }
    }

    infile.close();

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
