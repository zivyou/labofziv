#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] <= min){
                min = nums[i];
                nums[i] = INT_MIN;
            }
        }
        int max = INT_MIN;
        for (int i=nums.size()-1; i>=0; i--){
            if (nums[i] == INT_MIN){
                continue;
            }
            if (nums[i] < max )
                return true;
            else{
                max = nums[i];
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> v = {5,6};
    cout<<s.increasingTriplet(v)<<endl;
    return 0;
}
