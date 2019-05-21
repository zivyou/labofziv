#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int limit = nums.size();
        if (limit <= 1)
            return;
        for (int i=0; i<limit; i++){
            if (nums[i] == 0){
                nums.erase(nums.begin()+i);
                nums.push_back(0);
                limit--;
                i--;
            }
        }      
    }
};