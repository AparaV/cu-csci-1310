/*Assignment 4 CSCI 1310 Recitation 101
**Author: Aparajithan Venkateswaran
**TA: Camilla Lambrocco
*/

#include <iostream>

using namespace std;

void calculateSimilarity(double* similarity, string DNA1, string DNA2);//calculates similarity between DNA1 and DNA2
void calculateBestMatch(int* distance, int* index, string DNA1, string DNA2);//calculates best match between DNA1 and DNA2
string complementaryDNA(string orgDNA);//creates and returns a complementary DNA strand
void reverseDNA(string &DNA);//reverses the DNA strand

int main(){


    /*Initializing DNA*/
    string humanDNA =
    "CGCAAATTTGCCGGATTTCCTTTGCTGTTCCTGCATGTAGTTTAAACGAGATTGCCAG"
    "CACCGGGTATCATTCACCATTTTTCTTTTCGTTAACTTGCCGTCAGCCTTTTCTTTGAC"
    "CTCTTCTTTCTGTTCATGTGTATTTGCTGTCTCTTAGCCCAGACTTCCCGTGTCCTTTC"
    "CACCGGGCCTTTGAGAGGTCACAGGGTCTTGATGCTGTGGTCTTCATCTGCAGGTGTCT"
    "GACTTCCAGCAACTGCTGGCCTGTGCCAGGGTGCAGCTGAGCACTGGAGTGGAGTTTTC"
    "CTGTGGAGAGGAGCCATGCCTAGAGTGGGATGGGCCATTGTTCATG";
    string mouseDNA =
    "CGCAATTTTTACTTAATTCTTTTTCTTTTAATTCATATATTTTTAATATGTTTACTAT"
    "TAATGGTTATCATTCACCATTTAACTATTTGTTATTTTGACGTCATTTTTTTCTATTTC"
    "CTCTTTTTTCAATTCATGTTTATTTTCTGTATTTTTGTTAAGTTTTCACAAGTCTAATA"
    "TAATTGTCCTTTGAGAGGTTATTTGGTCTATATTTTTTTTTCTTCATCTGTATTTTTAT"
    "GATTTCATTTAATTGATTTTCATTGACAGGGTTCTGCTGTGTTCTGGATTGTATTTTTC"
    "TTGTGGAGAGGAACTATTTCTTGAGTGGGATGTACCTTTGTTCTTG";
    string unknownDNA =
    "CGCATTTTTGCCGGTTTTCCTTTGCTGTTTATTCATTTATTTTAAACGATATTTATAT"
    "CATCGGGTTTCATTCACTATTTTTCTTTTCGATAAATTTTTGTCAGCATTTTCTTTTAC"
    "CTCTTCTTTCTGTTTATGTTAATTTTCTGTTTCTTAACCCAGTCTTCTCGATTCTTATC"
    "TACCGGACCTATTATAGGTCACAGGGTCTTGATGCTTTGGTTTTCATCTGCAAGAGTCT"
    "GACTTCCTGCTAATGCTGTTCTGTGTCAGGGTGCATCTGAGCACTGATGTGGAGTTTTC"
    "TTGTGGATATGAGCCATTCATAGTGTGGGATGTGCCATAGTTCATG";

    /*Part 1 of Assignment*/
    double sim2Human;
    double sim2Mouse;
    calculateSimilarity(&sim2Human, humanDNA, unknownDNA);
    calculateSimilarity(&sim2Mouse, mouseDNA, unknownDNA);
    if(sim2Human > sim2Mouse){
        cout << "Human" << endl;
    }
    else if(sim2Human < sim2Mouse){
        cout << "Mouse" << endl;
    }
    else{
        cout << "Identity cannot be determined" << endl;
    }

    /*Part 2 of Assignment*/
    int distance, index;
    string subDNA;
    string choice;

    cout << "Enter a substring: ";
    getline(cin, subDNA);

    cout << "To which DNA do you want to compare?\nHuman or Mouse?" << endl;
    getline(cin, choice);


    //checking validity of choice
    while(choice != "Human" && choice != "Mouse"){
        cout << "Please enter a valid choice. The choice is case-sensitive.\nHuman or Mouse?" << endl;
        getline(cin, choice);
    }

    if(choice == "Human"){
        calculateBestMatch(&distance, &index, humanDNA, subDNA);
        //if match is found
        if(distance  < subDNA.length() - 1){
            cout << "Best Match: ";
            for(int i = index; i < index + subDNA.length(); ++i){
                cout << humanDNA[i];
            }
            double length = subDNA.length();
            double score = (length - distance) / length;//calculate similarity score
            cout << "\nBest Match Score: " << score << endl;
        }
        else{
            cout << "Match not found" << endl;
        }
    }

    else{
        calculateBestMatch(&distance, &index, mouseDNA, subDNA);
        if(distance  < subDNA.length() - 1){
            //if match is found
            cout << "Best Match: ";
            for(int i = index; i < index + subDNA.length(); ++i){
                cout << mouseDNA[i];
            }
            double length = subDNA.length();
            double score = (length - distance) / length;//calculate similarity score
            cout << "\nBest Match Score: " << score << endl;
        }
        else{
            cout << "Match not found" << endl;
        }
    }

    /*Part 3: Finding Complementary Strand*/
    string test1;
    cout << "Enter a DNA to find complementary strand: ";
    getline(cin, test1);
    string test2 = complementaryDNA(test1);
    cout << "The complementary strand is: " << test2 << endl;

    /*Part 4: Reversing DNA strand*/
    reverseDNA(test2);
    cout << "The reversed strand is: " << test2 << endl;

    return 0;

}

/*Calculate Similarity*/
void calculateSimilarity(double* similarity, string DNA1, string DNA2){

    if(DNA1.length() != DNA2.length()){
        cout << "ERROR: DNA strands do not match in length" << endl;
        return;
    }

    double length = DNA1.length();
    int hammingDistance = 0;

    for(int i = 0; i < length; ++i){
        if(DNA1[i] != DNA2[i]){
            ++hammingDistance;
        }
    }

    *similarity = (length - hammingDistance) / length;
}

/*Calculate Best Match*/
void calculateBestMatch(int* distance, int* index, string DNA1, string DNA2){
    int subLength = DNA2.length();
    int length = DNA1.length();
    int curr_hammDist = 0;
    int best_hammDist = subLength - 1; //best match should be longer than 1 matching base

    for(int i = 0; i <= length - subLength; ++i){
        for(int j = 0; j < subLength; ++j){
            if(DNA1[i+j] != DNA2[j]){
                curr_hammDist++;
            }
        }
        //update best hamming distance
        if(curr_hammDist < best_hammDist){
            best_hammDist = curr_hammDist;
            *index = i;
        }
        curr_hammDist = 0;//reset current hamming distance
    }
    *distance = best_hammDist;
}

/*Complementary DNA*/
string complementaryDNA(string orgDNA){
    string compDNA;
    //change each base to its complementary base
    for(int i = 0; i < orgDNA.length(); ++i){
        if(orgDNA[i] == 'A'){
            compDNA.append("T");
        }
        if(orgDNA[i] == 'T'){
            compDNA.append("A");
        }
        if(orgDNA[i] == 'G'){
            compDNA.append("C");
        }
        if(orgDNA[i] == 'C'){
            compDNA.append("G");
        }
    }
    //error checking for any invalid characters
    if(compDNA.length() != orgDNA.length()){
        cout << "ERROR: One or more bases could not be identified" << endl;
        return "UNKOWN";
    }
    return compDNA;
}

/*Reverse DNA strand*/
void reverseDNA(string &DNA){
    //exception
    if(DNA == "UNKOWN"){
        return;
    }

    //array reversal
    for(int i = 0; i < DNA.length()/2; ++i){
        char temp = DNA[i];
        DNA[i] = DNA[DNA.length() - 1 - i];
        DNA[DNA.length() - 1 - i] = temp;
    }
}
