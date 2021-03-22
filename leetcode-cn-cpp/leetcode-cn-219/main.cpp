#include <iostream>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        for (int i=0; i<nums.size(); i++){
            if (m.find(nums[i]) == m.end()){
                m[nums[i]] = i;
            }else{
                int j = m[nums[i]];
                if (i-j <= k && j-i <= k)
                    return true;
                else
                    m[nums[i]] = i;
            }
        }

        return false;
    }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
