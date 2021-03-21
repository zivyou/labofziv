#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rawReverse(vector<int>& v, int i, int j){
        int t;
        while (i<j){
            t = v[i];
            v[i] = v[j];
            v[j] = t;

            i++;j--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int cur = nums.size()-2;
        while (cur >= 0){
            if (nums[cur] < nums[cur+1])
                break;
            cur--;
        }

        cout<<" debug, cur="<<cur<<endl;
        if (cur < 0){
            rawReverse(nums, 0, nums.size()-1);
        }else {
            int j;
            for (j=nums.size()-1; nums[j] <= nums[cur]; j--);
            cout<<" debug, j="<<j<<endl;
            if (j >= 0) {
                int t = nums[j];
                nums[j] = nums[cur];
                nums[cur] = t;
            } else {
                rawReverse(nums, 0, nums.size() - 1);
                return;
            }
            rawReverse(nums, cur + 1, nums.size() - 1);
        }
    }
};

int main() {
    Solution s;
    vector<int> v = {1,2,3,4,5};
    s.nextPermutation(v);
    for (int i=0; i<v.size(); i++)
        cout<<v[i]<<", ";
    cout<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}