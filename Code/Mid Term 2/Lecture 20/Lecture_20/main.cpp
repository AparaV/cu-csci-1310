/**Lecture 20
 **Notes
 */

#include <iostream>
#include <vector>
#include <Array.h>

using namespace std;

int main(){

    Array first(0);
    cout << "Initial Data:" << endl;
    first.printData();
    first.appendData(5);
    first.appendData(10);
    cout << "5 and 10:" << endl;
    first.printData();
    cout << first.returnSize() << endl;
    first.updateVal(1, 20);
    cout << "New Data:" << endl;
    first.printData();

    first.insertVal(0, 0);
    cout << "new new data:" << endl;
    first.printData();
    return 0;
}
