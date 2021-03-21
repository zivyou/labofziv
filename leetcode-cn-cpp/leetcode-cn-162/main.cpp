#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int at(vector<int> &nums, int pos){
        if (pos < 0 || pos >= nums.size())
            return INT_MIN;
        return nums[pos];
    }
    int rawFindPeakElement(vector<int> &nums, int a, int b){
        if (a == b)
            return a;
        int mid = (a+b)/2;
        //cout<<"mid="<<mid<<endl;

        if (at(nums, mid-1) < at(nums, mid) && at(nums, mid) > at(nums, mid+1))
            return mid;
        if (at(nums, mid-1) <= at(nums, mid) && at(nums, mid) <= at(nums, mid+1)){
            return rawFindPeakElement(nums, mid+1, b);
        }else
            return rawFindPeakElement(nums, a, mid-1);
    }
    int findPeakElement(vector<int>& nums) {
        return rawFindPeakElement(nums, 0, nums.size()-1);
    }
};

int main()
{
    Solution s;
    vector<int> v({-2147483648,-2147483647});
    cout<<s.findPeakElement(v)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
