#include <iostream>

using namespace std;

int main(){
    int height;

    while (true){
        cout << "Enter the height of the mountain in ft." << endl;
        cin >> height;

        if (height == 29029){
            cout << height << " ft is the height of Mount Everest. It is the highest mountain." << endl;
            break;
        }
        else if (height == 28251){
            cout << height << " ft is the height of K2. It is the second highest mountain." << endl;
            break;
        }
        else if (height == 28169){
            cout << height << " ft is the height of Kangchenjunga. It is the third highest mountain." << endl;
            break;
        }
        else {
            cout << "Height does not match that of the three highest mountains. Please enter a correct height!!" << endl;
            continue;
        }
    }


    return 0;
}
