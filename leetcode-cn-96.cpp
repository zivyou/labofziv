#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n <= 1)
            return 1;
        int* dp = new int[n+1];
        dp[1] = 1;
        dp[0] = 1;
        for (int i=0; i<n; i++){
            int sum = 0;
            for (int j=1; j<=i+1; j++){
                sum += dp[j-1]*dp[i-j+1];
            }
            dp[i+1] = sum;
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    cout<<s.numTrees(3)<<endl;
    return 0;
}