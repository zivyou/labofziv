#include <cstdio>
#include <vector>

using namespace std;

class Solution {
private:
    int _(vector<vector<int>>& matrix, int x, int y) {
        int result = 0;
        int n = 0;
        while (x+n <matrix.size() && y+n < matrix[0].size()) {
            bool foundZero = false;
            for (int i=x; i<=x+n; i++) {
                if (matrix[i][y+n] == 0) {
                    foundZero = true; break;
                }
            }
            for (int j=y; j<=y+n; j++) {
                if (matrix[x+n][j] == 0) {
                    foundZero = true; break;
                }
            }
            if (foundZero) break;
            else {
                result++;
            }
            n++;
        }
        return result;
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int result = 0;
        if (matrix.empty()) return result;
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                if (matrix[i][j] == 1) {
                    auto t = _(matrix, i, j);
                    result += t;
                    printf("result[%d][%d] is %d\n", i, j, t);
                }
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> m = {{1,1},{1, 0}};
    Solution s;
    printf("%d\n", s.countSquares(m));
}
