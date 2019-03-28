#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int min(int a, int b){
        return a > b ? b : a;
    }
    int rawFindMin(vector<int> &nums, int begin, int end){
        if (begin == end)
            return nums[begin];
        if (begin+1 == end){
            return nums[begin] > nums[end] ? nums[end] : nums[begin];
        }

        int mid = (begin + end)/2;
        if (nums[begin] > nums[mid])
            return rawFindMin(nums, begin, mid);
        if (nums[mid] > nums[end])
            return rawFindMin(nums, mid, end);
        return min(rawFindMin(nums, begin, mid), rawFindMin(nums, mid, end));
    }
    int findMin(vector<int>& nums) {
        return rawFindMin(nums, 0, nums.size()-1);
    }
};

int main()
{
    Solution s;
    vector<int> v({3,4,5,1,2});
    cout<<s.findMin(v)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
