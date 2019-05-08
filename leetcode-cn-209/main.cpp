#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();

        int re = len;
        bool found = false;

        for (int i=0; i<len; i++){
            int sum = 0;
            for (int j=i; j<len; j++){
                if (sum + nums[j] < s){
                    sum = sum + nums[j];
                }else{
                    found = true;
                    if (j-i+1 < re){
                        re = j-i+1;
                    }
                    break;
                }
            }
        }
        if (found)
            return re;
        else
            return 0;
    }
};

int main()
{
    vector<int> v({2,3,1,2,4,3});
    Solution s;
    cout<<s.minSubArrayLen(7,v)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
