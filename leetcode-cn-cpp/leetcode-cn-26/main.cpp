#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();

        int i, j;
        for (i=0; i<length-1; i++){
            if (nums[i] == nums[i+1]){
                length --;
                for (j=i; j<nums.size()-1; j++)
                    nums[j] = nums[j+1];
                i--;
            }
        }

        return length;
    }
};

int main() {
    vector<int> v = {1, 1, 1, 1, 1, 2};
    Solution s;
    int re = s.removeDuplicates(v);
    for (int i=0; i<re; i++)
        cout<<v[i]<<", ";
    cout<<endl;
    return 0;
}