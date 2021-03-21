#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > re;
        for (int i=0; i<m; i++){
            re.push_back(vector<int>(n, 0));
        }
        
        for (int i=0; i<m; i++){
            re[i][0] = 1;
        }
        for (int i=0; i<n; i++){
            re[0][i] = 1;
        }

        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++){
                re[i][j] = re[i-1][j] + re[i][j-1];
            }
        
        return re[m-1][n-1];
    }
};

int main(){
    Solution s;
    cout<<s.uniquePaths(3, 2)<<endl;
}