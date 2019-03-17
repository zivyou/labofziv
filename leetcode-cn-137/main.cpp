#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bitCount[33] = {0};
        for (int i=0; i<nums.size(); i++){
            for (int j=0; j<32; j++){
                if (nums[i] & (1<<j)){
                    bitCount[j]++;
                }
            }
        }

        unsigned int re = 0;
        for (int i=0; i<32; i++){
            if (bitCount[i]%3){
                re = re | (1<<i);
            }
        }

        return re;
    }
};

int main()
{
    Solution s;
    vector<int> v({-3,-1,-1,-1});
    cout<<s.singleNumber(v)<<endl;
    return 0;
}
