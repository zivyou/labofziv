#include <iostream>

using namespace std;

class Solution {
public:

    int aliveAround(vector<vector<int>>& board, int i, int j){
        int count = 0;
        if (i-1 >= 0){
            if (j-1 >= 0)
                if (board[i-1][j-1] > 0)
                    count++;
            if (board[i-1][j] > 0)
                count++;
            if (j+1 < board[i].size())
                if (board[i-1][j+1] > 0)
                    count++;
        }

        if (j-1 >= 0)
            if (board[i][j-1] > 0)
                count++;
        if (j+1 < board[i].size())
            if (board[i][j+1]  > 0)
                count++;

        if (i+1 < board.size()){
            if (j-1 >= 0)
                if (board[i+1][j-1] > 0)
                    count++;
            if (board[i+1][j] > 0)
                count++;
            if (j+1 < board[i].size())
                if (board[i+1][j+1] > 0)
                    count++;
        }

        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[i].size(); j++){
                if (board[i][j] == 1){
                    if (aliveAround(board, i, j) < 2)
                        board[i][j] = 2;
                    if (aliveAround(board, i, j) > 3)
                        board[i][j] = 2;
                }else{
                    if (aliveAround(board, i, j) == 3)
                        board[i][j] = -1;
                }
            }
        }

        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[i].size(); j++){
                if (board[i][j] == 2)
                    board[i][j] = 0;
                else if (board[i][j] == -1)
                {
                    board[i][j] = 1;
                }else
                    continue;
                
            }
        }
    }
};

int main(){
    return 0;
}