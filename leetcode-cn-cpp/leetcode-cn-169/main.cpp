#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:

    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
