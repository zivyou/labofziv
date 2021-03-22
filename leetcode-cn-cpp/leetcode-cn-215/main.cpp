#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    static bool cmp(int a, int b){
        return b>a? 0 :1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        return nums[k-1];
    }
};


int main() {
    Solution s;
    vector<int> nums({3,2,3,1,2,4,5,5,6});
    cout<<s.findKthLargest(nums, 4)<<endl;
    return 0;
}