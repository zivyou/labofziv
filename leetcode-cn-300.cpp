#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int re[nums.size()];
        re[0] = 1;
        for (int i=1; i<nums.size(); i++){
            if (re[i] > re[i-1])
                re [i] = 1+re[i-1];
            else
            {
                re[i] = 1;
            }
        }

        int max = INT_MIN;
        for (auto v : re){
            if (v > max)
                max = v;
        }

        return max;
    }
};


int main(){
    return 0;
}