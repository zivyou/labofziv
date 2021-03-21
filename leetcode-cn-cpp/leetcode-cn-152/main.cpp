#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int maxProduct(vector<int>& nums){
        int numsSize = nums.size();
        int re[numsSize][numsSize] = {1};

        for (int i=0; i<nums.size(); i++){
            re[i][i] = nums[i];
        }

        int max = INT_MIN;
        for (int j=0; j<numsSize-1; j++)
        for (int i=j+1; i<numsSize; i++){
            re[j][i] = re[j][i-1] * nums[i];
            if (re[j][i] > max)
                max = re[j][i];
        }


        return max;
    }
};
*/
class Solution {
public:
    int myMax(int a, int b){
        return a>b? a :b;
    }
    int myMin(int a, int b){
        return a>b ? b : a;
    }
    int maxProduct(vector<int>& nums) {
        int max = nums[0];
        int min = nums[0];
        int maxres = max;

        for(int i=1;i<nums.size();i++){
            printf("i=%d, max=%d, max*nums[i]=%d\n", i, max, max*nums[i]);
            int tmp = max *nums[i];
            max = myMax(nums[i], myMax(max*nums[i], min*nums[i]));
            min = myMin(nums[i], myMin(tmp, min*nums[i]));

            maxres = myMax(maxres, max);
        }

        return maxres;
    }
};

int main()
{
    vector<int> nums({4,3,0,3,5});
    Solution s;
    cout<<s.maxProduct(nums)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
