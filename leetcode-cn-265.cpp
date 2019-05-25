#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n=costs.size();
        if (n < 1)
            return 0;
        int k=costs[0].size();
        if (k < 1)
            return 0;
        
        int re[n][k];
        for (int i=0; i<k; i++)
            re[0][i] = costs[0][i];
        for (int i=1; i<n; i++){
            int min1 = INT_MAX;
            int min2 = INT_MAX;
            for (int j=0; j<k; j++){
                if (re[i-1][j] < min1){
                    min2 = min1;
                    min1 = re[i-1][j];
                }else if (re[i-1][j] < min2){
                    min2 = re[i-1][j];
                }else
                {
                    continue;
                }
            }

            for (int j=0; j<k; j++){
                if (re[i-1][j] != min1){
                    re[i][j] = min1 + costs[i][j];
                }else{
                    re[i][j] = min2 + costs[i][j];
                }
            }
        }
        int ret = INT_MAX;
        for (int j=0; j<k; j++)
            if (re[n-1][j] < INT_MAX)
                ret = re[n-1][j];
        return ret;
    }
};

int main(){
    return 0;
}