/*File I/O*/

#include <iostream>
#include <fstream> //file stream functionality

using namespace std;

int countLines(string fileName){
    ifstream inFile;
    inFile.open(fileName);
    if(inFile.fail()){
        cout << "ERROR" << endl;
        return -1;
    }
    else{
        string line;
        int counter = 0;
        while(getline(inFile, line, '\n')){
            ++counter;
            //cout << counter << endl;
        }
        return counter;
    }

}

int main(){
    //iostream - cin, cout
    //fstream - file stream (read && write), flags for doing that
    //ifstream - read in file only
    //ofstream - write out data

    //Write into a file

    ofstream outFile;
    outFile.open("testFile.txt");//opens an existing file or creates a new file of name
    outFile << "Hello World" << endl;
    //create an inventory
    outFile << "Inventory" << endl;
    outFile << "Mats: " << 39.95 << endl;
    outFile << "Bulbs: " << 3.22 << endl;
    outFile << "Fuses: 1.08" << endl;
    outFile.close();

    //Read from a file

    ifstream inFile;
    inFile.open("testFile.txt");
    //error check
    if(inFile.fail()){
        cout << "ERROR" << endl;
    }
    else{
        cout << "File opened" << endl;
        string line;
        while(getline(inFile, line)){
            cout << line << endl;
        }
        inFile.close();
        cout << "File processed and closed\n" << endl;
    }

    //fstream

    fstream fs;
    string line;
    fs.open("testFile.txt", fstream::in | fstream::out | fstream::app);
    fs << "another line in file" << endl;
    fs.clear();
    fs.seekg(0, ios::beg); //move fs to beginning of file
    while(getline(fs, line)){
        cout << line <<endl;
    }
    fs.close();

    //count the number of lines in textToEnglish.csv file

    cout << "\nHello" << endl;
    cout << countLines("textToEnglish.csv") << endl;
    return 0;
}
