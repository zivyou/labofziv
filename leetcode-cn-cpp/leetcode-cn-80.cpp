#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++){
            cout<<"nums.size()="<<nums.size()<<endl;
            if (i+1<nums.size() && i+2<nums.size()){
                if (nums[i] == nums[i+1] && nums[i+1] == nums[i+2]){
                    nums.erase(nums.begin()+i+1);
                    i--;
                }
            }
        }

        return nums.size();
    }
};

int main(){
    vector<int> v({1,1,1,1,1,1,1,1,1,1});
    Solution s;
    cout<<s.removeDuplicates(v)<<endl;
}