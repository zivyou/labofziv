#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int re;
    void dfs(vector<int> & nums, int begin, int target, int count){
        if (count <= 0){
            if (target > 0)
                re++;
            return;
        }

        for (int i=begin; i<nums.size(); i++){
            dfs(nums, i+1, target-nums[i], count-1);
        }
    }
    int threeSumSmaller(vector<int>& nums, int target) {
        dfs(nums, 0, target, 3);
        return re;
    }
};

int main(){
    return 0;
}