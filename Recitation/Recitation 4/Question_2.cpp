#include <iostream>
#include <algorithm>

using namespace std;

bool isAnagram(string w1, string w2){
    string new1 = sort(w1.begin(), w1.end());
    string new2 = sort(w2.begin(), w1.end());

    if(w1 == w2){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    cout << isAnagram("word", "word") << endl;

    return 0;

}
