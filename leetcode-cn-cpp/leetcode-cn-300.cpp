#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 1)
            return 0;
        int re = 1;
        int count[nums.size()];
        for (int i=0; i<nums.size(); i++)
            count[i] = 1;
        
        for (int i=0; i<nums.size(); i++){
            for (int j=0; j<i; j++){
                if (nums[i] > nums[j]){
                    count[i] = max(count[j]+1, count[i]);
                }
                if (count[i] > re)
                    re = count[i];
            }
        }
        return re;
    }
};




int main(){
    return 0;
}