#include <iostream>
#include <vector>
#include <climits>
#include "../../mylib/tools/mylib.h"

using namespace std;


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m <= 0) return 0;
        int n = matrix[0].size();
        if (n <= 0) return 0;
        int len[m][n];
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                len[i][j] = 0;
                int min = INT_MAX;
                if (matrix[i][j] > '0') {
                    if (i<1 || j<1) {
                        min = 0;
                    } else {
                        min = std::min(min, len[i-1][j]);
                        min = std::min(min, len[i][j-1]);
                        min = std::min(min, len[i-1][j-1]);
                    }
                    len[i][j] = min + 1;
                }
            }
        }
        int re = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (len[i][j] > re) {
                    re = len[i][j];
                }
            }
        }
        return re * re;
    }
};

int main()
{
    Solution s;
    char a[] = {'1','0','1','0','0','1','0','1','1','1','1','1','1','1','1','1','0','0','1','0'};
    vector<vector<char> > v = matrixToVector(a, 4, 5);
    cout<<s.maximalSquare(v)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
