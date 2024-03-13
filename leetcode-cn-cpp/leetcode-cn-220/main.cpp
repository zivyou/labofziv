#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool compare(int a, int b, int c){
        long long aa = a;
        long long bb = b;
        long long cc = c;
        if (aa - bb <= cc && bb - aa <= cc)
            return true;
        return false;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for (int i=0; i < nums.size(); i++){
            for (int j=i+1; j<=i+k && j<nums.size(); j++){
                if (compare(nums[i], nums[j], t))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> v;
    int k = 100000; int t = 0;
    for (int i=1; i<=100000; i++) {
        v.push_back(i);
    }
    cout<<s.containsNearbyAlmostDuplicate(v, k, t)<<endl;
    return 0;
}
