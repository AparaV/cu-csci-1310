#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int OPEN = 0;
const int WALL = 1;
const int DESTINATION = 2;

class Stack{
public:
    Stack(int, int);
    ~Stack();
    void push(int a, int b);
    void pop();
    int top_x();
    int top_y();
private:
    vector<int> x;
    vector<int> y;
};

void mazeSolver(int [4][4], int, int, int, int);

int main(){

    ifstream filePtr;
    filePtr.open("assignment2_data.txt");
    int maze[4][4];

    if (!filePtr){
        cerr << "File not found!" << endl;
        return 1;
    }
    else{
        for (int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                filePtr >> maze[i][j];
            }
        }
    }

    mazeSolver(maze, 0, 0, 3, 3);

    return 0;
}

Stack::Stack(int a, int b){
    x.push_back(a);
    y.push_back(b);
}

Stack::~Stack(){
    std::cout << "Object deleted" << std::endl;
}

void Stack::push(int a, int b){
    x.push_back(a);
    y.push_back(b);
}

void Stack::pop(){
    x.pop_back();
    y.pop_back();
}

int Stack::top_x(){
    return x.back();
}

int Stack::top_y(){
    return y.back();
}

void mazeSolver(int maze[4][4], int startPos_x, int startPos_y, int target_x, int target_y){
    int currPos_x = startPos_x;
    int currPos_y = startPos_y;

    Stack path(startPos_x, startPos_y);

    while(maze[currPos_y][currPos_x] != DESTINATION){

        int flag = 0;

        //Adding all open spaces around current position to stack
        if(maze[currPos_y + 1][currPos_x] == OPEN){
            path.push(currPos_y+1, currPos_x);
            flag++;
            if(maze[currPos_y + 1][currPos_x + 1] == OPEN){
                path.push(currPos_y + 1, currPos_x + 1);
                flag++;
            }
        }

        if(maze[currPos_y][currPos_x + 1] == OPEN){
            path.push(currPos_y, currPos_x + 1);
            flag++;
            if(maze[currPos_y - 1][currPos_x + 1] == OPEN){
                path.push(currPos_y - 1, currPos_x + 1);
                flag++;
            }
        }
        if(maze[currPos_y][currPos_x - 1] == OPEN){
            path.push(currPos_y,currPos_x - 1);
            flag++;
            if(maze[currPos_y + 1][currPos_x - 1] == OPEN){
                path.push(currPos_y + 1, currPos_x - 1);
                flag++;
            }
        }

        if(maze[currPos_y - 1][currPos_x] == OPEN){
            path.push(currPos_y - 1, currPos_x);
            flag++;
            if(maze[currPos_y - 1][currPos_x - 1] == OPEN){
                path.push(currPos_y - 1, currPos_x - 1);
                flag++;
            }
        }



        //If path is blocked
        if (flag <= 1){
            path.pop();
        }

        currPos_x = path.top_x();
        currPos_y = path.top_y();

    }

    cout << "Path Found!" << endl;

}
