#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = (int)nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        if (len == 2) return nums[0] > nums[1] ? nums[0] : nums[1];

        int *re = new int[len]();
        int i = 0;
        re[0] = nums[0];
        re[1] = nums[1] > nums[0] ? nums[1] : nums[0];
        for (i=2; i<len; i++){
            if (re[i-1] > re[i-2]+nums[i])
                re[i] = re[i-1];
            else
                re[i] = re[i-2]+nums[i];
        }
        int value = re[len-1];
        delete[] re;
        return value;
    }
};


int main() {
    vector<int> v = {2, 1, 1, 2};
    Solution s;

    std::cout << s.rob(v) << std::endl;
    return 0;
}