#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int> > re;
        int m = obstacleGrid.size(); int n=obstacleGrid[0].size();
        for (int i=0; i<m; i++){
            re.push_back(vector<int>(n, 0));
        }
        re[0][0] = 1;
        bool found = false;
        for (int i=0; i<m; i++){
            if (obstacleGrid[i][0] == 1)
                found = true;
            if (found)
                re[i][0] = 0;
            else
                re[i][0] = 1;
        }

        found = false;
        for (int i=0; i<n; i++){
            if (obstacleGrid[0][i] == 1)
                found = true;
            if (found)
                re[0][i] = 0;
            else
                re[0][i] = 1;
        }

        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++){
                if (obstacleGrid[i][j])
                    re[i][j] = 0;
                else
                    re[i][j] = re[i-1][j] + re[i][j-1];
            }
        
        return re[m-1][n-1];
    }
};

int main(){
    Solution s;
}