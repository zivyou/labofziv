#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int count = 0;
        for (int x = grid.size()-1; x>=0; x--) {
            for (int y = grid[0].size()-1; y>=0; y--) {
                if (grid[x][y] < 0) count++;
                else break;
            }
        }
        return count;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<vector<int>> v = {{3,2}, {1,0}};
    printf("====================> %d\n", s.countNegatives(v));
}
