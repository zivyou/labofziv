#include <iostream>
#include <vector>
//https://leetcode-cn.com/problems/maximum-subarray/description/

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = (int)nums.size();
        int *re = new int[len]();
        int i = 0;
        for (i = 0; i<len; i++){
            if (i==0){
                re[i] = nums.at(i);
                continue;
            }
            if (re[i-1] < 0)
                re[i] = nums.at(i);
            else{
                re[i] = re[i-1] + nums.at(i);
            }
        }
        int max = re[0];
        for (i=0; i<len; i++){
            if (re[i] >= max)
                max = re[i];
        }
        delete[] re;
        return max;
    }
};

int main() {
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    vector<int> input(&arr[0], &arr[8]);
    cout<<s.maxSubArray(input)<<endl;
    return 0;
}