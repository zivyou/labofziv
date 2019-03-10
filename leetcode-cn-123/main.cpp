#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
    int rawMaxProfit(vector<int>& prices, int begin, int end) {
        if (begin >= end)
            return 0;
        int * re = new int[prices.size()+1];
        int * maxNum = new int[prices.size() + 1];
        int max = 0;
        maxNum[end] = 0;
        for (int i=end-1; i>=begin; i--){
            if (prices[i+1] > max){
                maxNum[i] = prices[i+1];
                max = prices[i+1];
            }else
                maxNum[i] = maxNum[i+1];
        }


        for (int i=begin; i<=end; i++){
            if (maxNum[i] - prices[i] < 0)
                re[i] = 0;
            else
                re[i] = maxNum[i] - prices[i];
        }
        max = 0;
        for (int i=begin; i<=end; i++)
            if (re[i] > max)
                max = re[i];
        delete[] maxNum;
        delete[] re;
        return max;
    }

    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int max = 0;
        for (int i=1; i<prices.size()-1; i++){
            int val = rawMaxProfit(prices, 0, i) + rawMaxProfit(prices, i+1, prices.size()-1);
            if (val > max)
                max = val;
        }
        int val = rawMaxProfit(prices, 0, prices.size()-1);
        if (val > max)
            return val;
        else
            return max;
    }*/

    int maxProfit(vector<int>& prices) {
        int dp[prices.size()+1][prices.size()+1];
        /*
        for (int i=0; i<prices.size()+1; i++)
            for (int j=0; j<prices.size()+1; j++)
                dp[i][j]  = 0;
                */

        int re = 0;

        for (int i=prices.size()-1; i>=0; i--)
        for (int j=i; j<prices.size(); j++){
            int max = 0;
            for (int k=i+1; k<j; k++){
                if (dp[i][k]+dp[k+1][j] > max){
                    max = dp[i][k]+dp[k+1][j];
                    printf("=========i=%d, k=%d, j=%d\n", i,k,j);
                }
            }
            if (prices[j] - prices[i] > max)
                max = prices[j] - prices[i];
            printf("i=%d, j=%d, max=%d\n", i,j,max);
            dp[i][j] = max;
            if (re < max)
                re = max;
        }

        return re;
    }
};

int main()
{
    vector<int> v({3,3,5,0,0,3,1,4});
    Solution s;
    cout<<s.maxProfit(v)<<endl;

    return 0;
}
