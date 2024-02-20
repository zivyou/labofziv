
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool _(vector<vector<char>>& grid, int x, int y, string& target, int at, int** visited) {
        if (at >= target.length()) return true;
        auto c = target[at];
        if (visited[x][y]) return false;
        if (grid[x][y] != c) return false;
        visited[x][y] = 1;
        if (at+1 >= target.length()) return true;

        // printf("current at:%d,%d\n", x,y);
        if (x+1<grid.size()) {
            if (_(grid, x+1, y, target, at+1, visited))
                return true;
        }
        if (x-1>=0) {
            if(_(grid, x-1, y, target, at+1, visited))
                return true;
        }
        if (y+1<grid[0].size()) {
            if (_(grid, x, y+1, target, at+1, visited))
                return true;
        }
        if (y-1>=0) {
            if(_(grid, x, y-1, target, at+1, visited))
                return true;
        }
        visited[x][y] = 0;
        return false;
    }
    bool wordPuzzle(vector<vector<char>>& grid, string target) {
        if (grid.empty()) return false;
        int m = grid.size();
        int n = grid[0].size();
        for (int x=0; x<m; x++) {
            for (int y=0; y<n; y++) {
                auto c = grid[x][y];
                if (c != target[0]) continue;
                int** visited = new int*[m];
                for (int i=0; i<m; i++) {
                    visited[i] = new int[n];
                    fill_n(visited[i], n, 0);
                }
                auto result = _(grid, x,y, target, 0, visited);
                for (int i=0; i<m; i++) delete[] visited[i];
                delete[] visited;
                if(result) return true;
            }
        }
        return false;
    }
};


int main(int argc, char* argv[]) {
    Solution s;
    vector<vector<char>> map = vector<vector<char>>(3, vector<char>(4)) = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    printf("%d\n", s.wordPuzzle(map, "SEE"));
}
