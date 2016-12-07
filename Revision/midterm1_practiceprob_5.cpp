#include <iostream>
using namespace std;

int largestElements(int arr[3][3][3]){

    int a;
    int b;
    a = arr[0][0][0];
    int m, n, o;
    m = 0;
    n = 0;
    o = 0;

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++i){
            for(int k = 0; k < 3; ++k){
                if( arr[i][j][k] > a){
                    a = arr[i][j][k];
                    m = i;
                    n = j;
                    o = k;
                }
            }
        }
    }

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++i){
            for(int k = 0; k < 3; ++k){
                if(i == 0 && j == 0 && k == 0 && m != i && n != j && o != k){
                    b = arr[i][j][k];
                }
                else{
                    ++k;
                    b = arr[i][j][k];
                }
                if( arr[i][j][k] > b && m != i && n != j && o != k){
                    b = arr[i][j][k];
                }
            }
        }
    }

    return a + b;
}

int main() {

	int arr[3][3][3] = {{{1,2,3},{15,16,0},{12,22,35}},{{1,4,5},{65,0,0},{0,7,2}},{{24,34,7},{0,0,0},{3,7,19}}};
	cout << largestElements(arr) << endl;

    /*
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            for(int k = 0; k < 3; ++k){
                cout << arr[i][j][k] << " " ;
            }
            cout << "\t";
        }
        cout << endl;
    }
    */

	return 0;
}
