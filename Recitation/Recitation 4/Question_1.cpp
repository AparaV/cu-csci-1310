#include <iostream>
//#include <string>

using namespace std;

bool isPalindrome(string word){
    int last = (word.length() - 1);
    for(int i = 0; i < last/2; ++i){
        if(word[i] != word[last - 1]){
            return false;
        }
    }
    return true;
}

int main(){

    cout << isPalindrome("racecar") << endl;

    return 0;
}
