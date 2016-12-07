#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

void convertSeconds(int); // Function prototype for Problem 1
void playGame(); // Function prototype for Problem 2
void solveMaze(int[4][4]); //Function prototype for Problem 3

int main(){

    srand(clock()); // Seeding the random number generator with clock time
    bool flag = true;

    /* Solution to Problem 1 */

    cout << "Solution to Problem 1\n" << endl;

    int seconds;
    while (flag){
        cout << "Enter the number of seconds. Should be between 0 and 86,400" << endl;
        cin >> seconds;
        if (seconds >= 0 && seconds <= 86400){
            convertSeconds(seconds);
            flag = false;
        }
        else {
            cout << "The number of seconds is not within range." << endl;
        }
    }

    cout << endl << "==============\n" << endl;

    /* Solution to Problem 2 */

    cout << "Solution to Problem 2\n" << endl;

    playGame();

    cout << endl << "==============\n" << endl;

    /* Solution to Problem 3 */

    cout << "Solution to Problem 3\n" << endl;

    int maze[4][4] = {0};

    //Defining walls and apple position in the 2D array
    maze[3][3] = 2; //Value of apple's position
    maze[3][0] = 1;
    maze[3][1] = 1;
    maze[2][3] = 1;
    maze[1][3] = 1;
    maze[1][1] = 1;
    maze[0][3] = 1;

    solveMaze(maze);

    cout << endl << "==============\n" << endl;

    /* Solution to Problem 4 (Challenge Exercise) */

    cout << "Solution to Problem 4 (Challenge Exercise)\n" << endl;

    //Assume that the size of the array is fixed = 4 * 4
    char fileName[20];
    cout << "Enter the name of the file (maximum 20 characters)." << endl;
    cin >> fileName;

    ifstream filePtr;
    int maze2[4][4];

    filePtr.open(fileName);

    if(!filePtr){
        cerr << "Error: File not found" << endl;
    }
    else{

        cout << "Opening and reading input from file '" << fileName << "' ..." << endl;

        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                filePtr >> maze2[i][j];
            }
        }

        solveMaze(maze2);
    }

    cout << endl << "==============\n" << endl;

    return 0;
}

/* Function for Problem 1 */
void convertSeconds(int seconds){
    int H, M;
    H = seconds / 3600;
    seconds %= 3600;
    M = seconds / 60;
    seconds %= 60;
    cout << "The time is " << H << " hours, " << M << " minutes, and " << seconds << " seconds." << endl;
}

/* Function for Problem 2*/
void playGame(){

    bool flag = true;

    cout << "Good morning Sir. What is your name?" << endl;
    string name;
    cin >> name;
    cout << "Sir " << name << ", the kingdom is in peril..." << endl;
    cout << "It has been 3 months since the other knights of the Round Table went missing..." << endl;
    cout << "Only you can save our homeland now..." << endl;

    //The game loop begins
    while (flag){
        cout << "What do you want to do now? Press the number corresponding to the option..." << endl;
        cout << "0 - Go Home..." << endl;
        cout << "1 - Fight the Dragon..." << endl;
        cout << "2 - Save the Princess..." << endl;
        int choice;
        cin >> choice;

        if (choice == 0){
            cout << "Wimp!" << endl;
            flag = false;
        }
        else if (choice == 1){
            int winChance = rand() % 2;
            if (winChance == 1)
                cout << "You Won!" << endl;
            else {
                cout << "You Lost!" << endl;
                flag = false;
            }
        }
        else if (choice == 2){
            cout << "You saved the Princess!" << endl;
        }
        else {
            cout << "Your choice does not make sense, Sir " << name << "!" << endl;
        }
    }
}

/* Function for Problem 3 */
void solveMaze(int maze[4][4]){
    const int applePos_x = 3;
    const int applePos_y = 3;
    const int WALL = 1;
    const int APPLE = 2;
    int horsePos_x = 0;
    int horsePos_y = 0;


    while (maze[horsePos_y][horsePos_x] != APPLE){

        if (horsePos_x < applePos_x){
            if (maze[horsePos_y][horsePos_x + 1] != WALL){
                horsePos_x++;
                cout << "Go right." << endl;
                //cout << "Current Position of Horse: (" << horsePos_y << ", " << horsePos_x << ")" << endl;
            }
        }

        if (horsePos_x > applePos_x){
            if (maze[horsePos_y][horsePos_x - 1] != WALL){
                horsePos_x--;
                cout << "Go left." << endl;
                //cout << "Current Position of Horse: (" << horsePos_y << ", " << horsePos_x << ")" << endl;
            }
        }

        if (horsePos_y < applePos_y){
            if (maze[horsePos_y + 1][horsePos_x] != WALL){
                horsePos_y++;
                cout << "Go up." << endl;
                //cout << "Current Position of Horse: (" << horsePos_y << ", " << horsePos_x << ")" << endl;
            }
        }

        if (horsePos_y > applePos_y){
            if (maze[horsePos_y - 1][horsePos_x] != WALL){
                horsePos_y--;
                cout << "Go down." << endl;
                //cout << "Current Position of Horse: (" << horsePos_y << ", " << horsePos_x << ")" << endl;
            }
        }
    }
}
