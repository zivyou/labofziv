#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1; int right = nums.size()-1;
        int mid;
        while (left <= right){
            mid = (left+right)/2;
            int count = 0;
            for (auto v : nums){
                if (v <= mid)
                    count++;
            }
            if (count == mid){
                left = mid+1;
            }else if (count > mid){
                right = mid - 1;
            }else{
                left = mid+1;
            }
        }

        return mid;
    }
};

int main(){
    Solution s;
    vector<int> v = {1,3,4,2,1};
    cout<<s.findDuplicate(v)<<endl;
    return 0;
}