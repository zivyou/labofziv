#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (!nums.size())
            return vector<int>();
        sort(nums.begin(), nums.end());
        int min = nums[0]; int max = nums[nums.size()-1];
        vector<int> trueRe;
        trueRe.push_back(min);

        for (int i=0; i<nums.size(); i++){
            vector<int> result;

            int base = nums[i];
            for (int j=i; j<nums.size(); j++) {
                if (nums[j]%base == 0) {
                    result.push_back(nums[j]);
                    base = nums[j];
                }else{

                }
            }

            if (result.size() > trueRe.size())
                trueRe = result;

        }

        return trueRe;
    }
};

int main()
{
    Solution s;
    vector<int> data = {1,2,3};
    vector<int> re = s.largestDivisibleSubset(data);
    for (auto i: re)
        cout<<i<<" ";
    cout<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
