#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = (int)nums.size();
        int i, j;
        vector<int> ret;
        for (i=0; i<length; i++)
            for (j=i+1; j<length; j++)
                if ((nums[i] + nums[j]) == target){
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
    }
};

int main() {
    vector<int> nums = {3, 2, 4};
    Solution s;
    vector<int> ret = s.twoSum(nums, 6);
    cout<<ret.size()<<endl;
    cout<<ret[0]<<" "<<ret[1]<<endl;
    return 0;
}