#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool path(vector<vector<char> >& board, int pos[2], string word){
        cout<<"word="<<word<<",pos[0]="<<pos[0]<<", pos[1]="<<pos[1]<<endl;
        if (board[pos[0]][pos[1]] != word[0])
            return false;
        char data = word[0];
        word.erase(word.begin());
        if (word.length() == 0)
            return true;
        int x=pos[0]; int y=pos[1];
        board[x][y] = 0;

        if (y > 0){
            int newPos[2];
            newPos[0] = x;
            newPos[1] = y-1;
            if (path(board, newPos, word))
                    return true;
        }

        if (y+1 < board[x].size()){
            int newPos[2];
            newPos[0] = x;
            newPos[1] = y+1;
            if (path(board, newPos, word))
                    return true;
        }

        if (x > 0){
            int newPos[2];
            newPos[0] = x-1;
            newPos[1] = y;
            if (path(board, newPos, word))
                    return true;
        }

        if (x+1 < board.size()){
            int newPos[2];
            newPos[0] = x+1;
            newPos[1] = y;
            if (path(board, newPos, word))
                    return true;
        }
        board[x][y] = data;
        return false;
    }
    bool exist(vector<vector<char> >& board, string word) {
        if (word.length() == 0)
            return 0;
        

        for (int i=0; i<board.size(); i++)
            for (int j=0; j<board[i].size(); j++){
                int pos[2];
                pos[0] = i;
                pos[1] = j;

                if (board[i][j] == word[0])
                    if (path(board, pos, word))
                        return true; 
            }
        return false;
    }
};

int main(){
    vector<vector<char> > board;
    board.push_back(vector<char>({'A','B','C','E'}));
    board.push_back(vector<char>({'S','F','C','S'}));
    board.push_back(vector<char>({'A','D','E','E'}));
    Solution s;
    if (s.exist(board, "SEE"))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
}