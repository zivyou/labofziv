#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<char> >& board, vector<vector<char>>& color, int a, int b){

        if (a < 0 || a >= board.size())
            return;

        if (b < 0 || b >= board[a].size())
            return;
        if (board[a][b] == 'X')
            return;
        if (color[a][b] == 'B')
            return;

        color[a][b] = 'B';
        dfs(board, color, a-1, b);
        dfs(board, color, a+1, b);
        dfs(board, color, a, b-1);
        dfs(board, color, a, b+1);
    }
    void solve(vector<vector<char>>& board) {

        if (board.size() <= 0)
            return;
        vector<vector<char>> color = board;
        for (int i=0; i<board[0].size(); i++){
            if (board[0][i] == 'O')
                dfs(board, color, 0, i);
        }


        for (int i=0; i<board[board.size()-1].size(); i++){
            if (board[board.size()-1][i] == 'O')
                dfs(board, color, board.size()-1, i);
        }


        for (int i=0; i<board.size(); i++){
            if (board[i][0] == 'O')
                dfs(board, color, i, 0);
        }

        for (int i=0; i<board.size(); i++){
            if (board[i][board[i].size()-1] == 'O')
                dfs(board, color, i, board[i].size()-1);
        }

        for (int i=0; i<board.size(); i++)
            for (int j=0; j<board[i].size(); j++)
                if (color[i][j] != 'B')
                    board[i][j] = 'X';
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board;
    board.push_back(vector<char>({'X','X','X','X'}));
    board.push_back(vector<char>({'X','O','O','X'}));
    board.push_back(vector<char>({'X','X','O','X'}));
    board.push_back(vector<char>({'X','O','X','X'}));
    s.solve(board);

    for (int i=0; i<board.size(); i++){
        for (int j=0; j<board[i].size(); j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
