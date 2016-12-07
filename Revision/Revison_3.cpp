#include <iostream>

using namespace std;

//number of times a character is repeated
int repeats(string arr[10], char x){
    int counter = 0;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < arr[i].length(); ++j){
            if(arr[i][j] == x){
                ++counter;
            }
        }
    }
    return counter;
}

//length of array even or odd
bool isEven(int a[]){
    int length = 0;

    for(length = 0; a[length] != -1; ++length){
    }
    //length is now one less than actual array length
    if(++length % 2 == 0){
        return true;;
    }
    return false;
}

//compare two arrays and returns the first index where they're different (same size arrays) return -1 if same

int main(){

    string s[10];
    s[0] = "qwer";
    s[1] = "tyui";
    s[2] = "uiop";
    s[3] = "asdf";
    s[4] = "sdfg";
    s[5] = "dfgh";
    s[6] = "hjkl";
    s[7] = "aaaa";
    s[8] = "bbbb";
    s[9] = "aaaa";

    cout << repeats(s, 'a') << endl;

    int a[] = {1, 2, 3, -1};

    cout << boolalpha << isEven(a) << endl;

    return 0;
}
