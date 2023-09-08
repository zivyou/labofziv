#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> f(n, 0);
        vector<int> g(n, 0);

        f[0] =nums[0]; f[1] = std::max(nums[0], nums[1]);
        g[1] = nums[1]; g[0] = 0;
        for (int i=2; i<n; i++) {
            f[i] = std::max(f[i-2]+nums[i], f[i-1]);
        }
        for (int i=2; i<n; i++) {
            g[i] = std::max(g[i-2]+nums[i], g[i-1]);
        }
        return std::max(f[n - 2], g[n-1]);
    }
};

int main()
{
    Solution s;
    vector<int> v({1,2,3});
    cout<<s.rob(v)<<endl;
    /*1,2,3,4,0,1,8*/
    cout << "Hello world!" << endl;
    return 0;
}
