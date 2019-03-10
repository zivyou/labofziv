#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void swap(int &a, int &b){
        int t=a;
        a=b;
        b=t;
    }
    int firstMissingPositive(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++){
            if (nums[i]<=0 || nums[i] == i+1 || nums[i] > nums.size())
                continue;
            if (nums[i] > i+1){
                if (nums[nums[i]-1] != nums[i]){
                    swap(nums[i], nums[nums[i]-1]);
                    i--;
                }
            }
        }

        for (int i=nums.size()-1; i>=0; i--){
            if (nums[i]<=0 || nums[i] == i+1 || nums[i] > nums.size())
                continue;

            if (nums[i] < i+1){
                if (nums[nums[i]-1] != nums[i]){
                    swap(nums[i], nums[nums[i]-1]);
                    i++;
                }
            }
        }
//        for (int i=0; i<nums.size(); i++)
//            cout<<nums[i]<<" ";
//        cout<<endl;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] != i+1)
                return i+1;
        }

        return nums.size()+1;
    }
};
int main()
{
    vector<int> v = {1,2,0};
    Solution s;
    cout << s.firstMissingPositive(v)<< endl;
    return 0;
}
