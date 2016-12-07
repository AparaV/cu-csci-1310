#include <iostream>

using namespace std;

bool sudoku(int board[9][9]){
    int col_sum = 0;
    int row_sum = 0;
    int col_prod = 1;
    int row_prod = 1;
    bool flag = false;

    for(int i = 0; i < 9; ++i){

        for(int j = 0; j < 9; ++j){
            row_sum += board[i][j];
            col_sum += board[j][i];

            row_prod *= board[i][j];
            col_prod *= board[j][i];
        }

        if(row_sum != 45 || col_sum != 45 || row_prod != 362880 || col_prod != 362880){
            return false;
        }

        row_sum = col_sum = 0;
        row_prod = col_prod = 1;
    }


}

int main(){

    return 0;
}
