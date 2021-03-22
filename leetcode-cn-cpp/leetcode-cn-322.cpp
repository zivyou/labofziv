#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        for (int i=0; i<amount+1; i++)
            dp[i] = -1;
        dp[0] = 0;
        for (int i=1; i<=amount; i++){
            int min = INT_MAX;
            for (int j=0; j<coins.size(); j++){
                if (i-coins[j] >= 0){
                    if (dp[i-coins[j]] != -1 && dp[i-coins[j]]+1 < min)
                        min = dp[i-coins[j]]+1;
                }
            }
            if (min != INT_MAX)
                dp[i] = min;
        }

    
        return dp[amount];

    }
};


int main(){
    vector<int> v({2});
    Solution s;
    cout<<s.coinChange(v, 3)<<endl;;
    return 0;
}