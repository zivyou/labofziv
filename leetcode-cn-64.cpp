#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int min(int a, int b){
        return a>b?b:a;
    }
    int minPathSum(vector<vector<int> >& grid) {
        vector<vector<int> > re;
        int m = grid.size(); int n=grid[0].size();
        for (int i=0; i<m; i++){
            re.push_back(vector<int>(n, 0));
        }
        re[0][0] = grid[0][0];
        for (int i=1; i<m; i++){
            re[i][0] = re[i-1][0] + grid[i][0];
        }

        for (int i=0; i<n; i++){
            re[0][i] = re[0][i-1] + grid[0][i];
        }

        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++){
                re[i][j] = min(re[i-1][j]+grid[i][j], re[i][j-1]+grid[i][j]);
            }
        
        return re[m-1][n-1];
    }
};

int main() {

}