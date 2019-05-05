#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int re = nums[0];
        for (int i=1; i<nums.size(); i++){
            re = re ^ nums[i];
        }
        return re;
    }
};
int main()
{
    Solution s;
    vector<int> v({4,1,2,1,2});
    cout<<s.singleNumber(v)<<endl;
    return 0;
}
