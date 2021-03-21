#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>>& rooms, int i, int j){
        //left
        if (i > 0){
            if (rooms[i-1][j] > rooms[i][j]+1){
                rooms[i-1][j] = rooms[i][j]+1;
                bfs(rooms, i-1, j);
            }
        }

        //top
        if (j > 0){
            if (rooms[i][j-1] > rooms[i][j]+1){
                rooms[i][j-1] = rooms[i][j]+1;
                bfs(rooms, i, j-1);
            }
        }

        //right
        if (j < rooms[i].size()-1){
            if (rooms[i][j+1] > rooms[i][j]+1){
                rooms[i][j+1] = rooms[i][j]+1;
                bfs(rooms, i, j+1);
            }
        }

        //bottom
        if (i < rooms.size()-1){
            if (rooms[i+1][j] > rooms[i][j]+1){
                rooms[i+1][j] = rooms[i][j]+1;
                bfs(rooms, i+1, j);
            }
        }
    }

    void wallsAndGates(vector<vector<int>>& rooms) {
        for (int i=0; i<rooms.size(); i++){
            for (int j=0; j<rooms[i].size(); j++){
                if (rooms[i][j] == 0){
                    bfs(rooms, i, j);
                }
            }
        }
    }
};


int main(){
    Solution s;

    return 0;
}