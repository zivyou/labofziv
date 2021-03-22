#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() < 3){
            for (int i=0; i<nums.size(); i++){
                if (nums[i] == target)
                    return true;
            }
            return false;
        }
        int l=0; int r=nums.size()-1;
        int mid;
        while (l<r){
            mid = (l+r)/2;
            cout<<"mid = "<<mid<<endl;
            if (nums[mid] == target)
                return true;
            if (nums[l] >= nums[r]){
                if (nums[mid] > target){
                    
                }
            }else{
                if (target > nums[mid])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        if (l == r && nums[l] == target)
            return true;
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums({4,5,6,7,0,1,2});
    cout<<s.search(nums, 0)<<endl;
}