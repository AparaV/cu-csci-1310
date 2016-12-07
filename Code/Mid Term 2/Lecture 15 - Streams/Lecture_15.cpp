#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Word{
    string abbrev;
    string translate;
};

int main(){

    Word myWord;
    myWord.abbrev = "lol";
    myWord.translate = "laugh out loud";

    int arrayLength = 4267;
    Word abbreviations[arrayLength];

    //type conversions using streams
    int x = 1234;
    double y = 4.5;
    stringstream ss2;
    ss2 << y;
    ss2 >> x;

    cout << x << endl;


    ifstream file;
    file.open("textToEnglish.csv");
    //error check
    if(file.fail()){
        cout << "ERROR" << endl;
    }
    else{
        //read file
        string line;
        int lineIndex = 0;//index for array of structs Word

        while(getline(file, line, '\r')){

            //get individual strings from each column
            //stringstream creates a stream out of a string
            stringstream ss;
            ss << line;

            int wordIndex = 0;//keeps track of the member needed to be updated
            while(getline(ss, line, ',')){
                //cout << line << endl;
                if(wordIndex == 0){
                    abbreviations[lineIndex].abbrev = line;
                }
                else if(wordIndex == 1){
                    abbreviations[lineIndex].translate = line;
                }
                wordIndex++;//will become 1 in next iteration and then gets reset to 0 when moving to next line
            }

            lineIndex++;//go to next struct in array in next iteration;

        }

    }
    //write something that is searchable
    //for(int i = 0; i < arrayLength; ++i){
    //    cout << abbreviations[i].abbrev << " " << abbreviations[i].translate << endl;
    //}

    //search for abbreviation and translate it
    string abbrev;
    cout << "Enter an abbreviation: ";
    cin >> abbrev;

    for(int i = 0; i < arrayLength; ++i){
        if(abbreviations[i].abbrev == abbrev){
            cout << "Translation: " << abbreviations[i].translate << endl;
            break;
        }
    }

    return 0;
}
