#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

class Solution {
private:
    int** dp1; int** dp2; int** dp3;
    int target1, target2, target3;
    int _(vector<int>& nums, int begin, int end, int target) {
        if (end <= begin) return 0;
        if (target == target1 && dp1[begin][end] >= 0) return dp1[begin][end];
        if (target == target2 && dp2[begin][end] >= 0) return dp2[begin][end];
        if (target == target3 && dp3[begin][end] >= 0) return dp3[begin][end];
        int max = INT_MIN;
        if (nums[begin]+nums[begin+1] == target) {
            auto x = _(nums, begin+2, end, target) + 1;
            if (x > max) {
                max = x;
            }
        }
        if (nums[begin]+nums[end] == target) {
            auto x = _(nums, begin+1, end-1, target) + 1;
            if (x > max) {
                max = x;
            }
        }

        if (nums[end-1]+nums[end]==target) {
            auto x = _(nums, begin, end-2, target) + 1;
            if (x > max) {
                max = x;
            }
        }
        if (max > 0) {
            if (target == target1) {
                dp1[begin][end] = max;
            }
            if (target == target2) {
                dp2[begin][end] = max;
            }
            if (target == target3) {
                dp3[begin][end] = max;
            }
            return max;
        }
        else return 0;
    }
public:
    int maxOperations(vector<int>& nums) {
        target1 = nums[0]+nums[1];
        target2 = nums[0]+nums[nums.size()-1];
        target3 = nums[nums.size()-2]+nums[nums.size()-1];
        int size = nums.size();
        dp1 = new int*[size];
        dp2 = new int*[size];
        dp3 = new int*[size];
        for (int i=0; i<size; i++) {
            dp1[i] = new int[size];
            dp2[i] = new int[size];
            dp3[i] = new int[size];
            fill_n(dp1[i], size, -1);
            fill_n(dp2[i], size, -1);
            fill_n(dp3[i], size, -1);
        }
        auto x1 = _(nums, 0, nums.size()-1, target1);
        auto x2 = _(nums, 0, nums.size()-1, target2);
        auto x3 = _(nums, 0, nums.size()-1, target3);
        for (int i=0; i<size; i++) {
            delete[] dp1[i];
            delete[] dp2[i];
            delete[] dp3[i];
        }
        return max(x1, max(x2, x3));
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> v = {3,2,6,1,4};
    printf("%d\n", s.maxOperations(v));
}
