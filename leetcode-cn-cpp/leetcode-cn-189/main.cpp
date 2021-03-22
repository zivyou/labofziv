#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 1)
            return;
        k = k%len;
        int count = 0;
        int start = 0;
        int curIndex = start;
        int tmp = nums[0];
        while (count < len && start < k){
            int nextIndex = (curIndex+k)%len;
            int nextVal = nums[nextIndex];
            nums[nextIndex] = tmp;
            tmp = nextVal;
            curIndex = nextIndex;
            if (curIndex == start ){
                start++;
                curIndex = start;
                tmp = nums[start];
            }
            count++;
        }
    }
};

int main()
{
    vector<int> v({1,2,3,4,5,6});
    Solution s;
    s.rotate(v, 2);
    for (int i=0; i< v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}
