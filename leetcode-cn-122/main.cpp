#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int dp[prices.size()+1];
        for (int i=0; i<=prices.size(); i++)
            dp[i] = 0;
        for (int i=1; i<prices.size(); i++){
            if (prices[i] < prices[i-1])
                dp[i+1] = dp[i];
            else {
                int max = 0;
                for (int k=0; k<i; k++){
                    if (dp[k] + prices[i]-prices[k] > max)
                        max = dp[k] + prices[i]-prices[k];
                }
                //printf("i=%d, max=%d\n", i, max);
                dp[i+1] = max;
            }
        }

        int max = 0;
        for (int i=0; i<=prices.size(); i++){
            if (dp[i] >max)
                max = dp[i];
            //printf("dp[%d]=%d\n", i, dp[i]);
        }

        return max;
    }
};

int main()
{
    vector<int> v({18,4, 1, 15, 36, 31, 25});
    Solution s;
    cout<<s.maxProfit(v)<<endl;
    return 0;
}
