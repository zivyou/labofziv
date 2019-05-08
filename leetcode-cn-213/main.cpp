#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        if (len == 2)
            return 0;
        int dp[len];
        bool choosed;
        dp[0] = nums[0];
        bool firstChoosed = false;
        if (nums[1] > nums[0]){
            dp[1] = nums[1];
            choosed = true;
            firstChoosed = false;
        }else{
            dp[1] = nums[0];
            choosed = false;
            firstChoosed = true;
        }

        for (int i=2; i<len; i++){
            if (choosed){
                if (dp[i-2] + nums[i] < dp[i-1]){
                    choosed = false;
                    dp[i] = dp[i-1];
                }else{
                    dp[i] = dp[i-2] + nums[i];
                    choosed = true;
                }
            }else {
                if (dp[i-2] > dp[i-1]){
                    dp[i] = dp[i-2] + nums[i];
                }else
                    dp[i] = dp[i-1] + nums[i];
                choosed = true;
            }
        }

        if (!choosed)
            return dp[len-2];
        else{
            if (firstChoosed)
                return dp[len-2];
            else
                return dp[len-1];
        }
    }
};

int main()
{
    Solution s;
    vector<int> v({1,2,3,4,0,1,8});
    cout<<s.rob(v)<<endl;
    /*1,2,3,4,0,1,8*/
    cout << "Hello world!" << endl;
    return 0;
}
