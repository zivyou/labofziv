#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int dp[prices.size()];
        for (int i=0; i<prices.size(); i++){
            if (prices[i] - prices[0] > 0)
                dp[i] = prices[i] - prices[0];
            else
            {
                dp[i] = 0;
            }
            
        }
        int re = 0;
        for (int i=1; i<prices.size(); i++){
            if (prices[i] < prices[i-1])
                dp[i] = dp[i-1];
            else{
                int max = 0;
                for (int j=1; j<=i; j++){
                    int dpt;
                    if (j >= 2)
                        dpt = dp[j-2];
                    else
                    {
                        dpt = 0;
                    }
                    
                    if (dpt + prices[i] - prices[j] > max){
                        max = dpt + prices[i] - prices[j];
                    }
                }
                if (max > dp[i])
                    dp[i] = max;
            }
        }
        
        for (int i=0; i<prices.size(); i++){
            if (dp[i] > re)
                re = dp[i];
        }
        return re;
    }
};
int main(){
    return 0;
}