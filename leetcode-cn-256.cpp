#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int re[n][3];
        re[0][0] = costs[0][0];
        re[0][1] = costs[0][1];
        re[0][2] = costs[0][2];

        for (int i=1; i<n; i++){
            for (int j=0; j<3; j++){
                int n1 = (j+1)%3;
                int n2 = (j+2)%3;
                re[i][j] = std::min(re[i-1][n1]+costs[i][j], re[i-1][n2]+costs[i][j]);
            }
        }

        return std::min(re[n-1][0], std::min(re[n-1][1], re[n-1][2]));
    }
};

int main(){
    return 0;
}