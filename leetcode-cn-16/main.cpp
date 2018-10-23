#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int compare(int &a, int &b){
        if (a < b)
            return 1;
        else
            return 0;
    }
    int vectorSum(vector<int>& nums){
        int re=0;
        for (int i=0; i<nums.size(); i++){
            re = re+nums[i];
        }
        return re;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() <= 3) return vectorSum(nums);

        sort(nums.begin(), nums.end(), compare);
        int i, j, k;
        for (i=0; i<nums.size(); i++)
            cout<<nums[i]<< " ";
        cout<<endl;
        int min = INT_MAX;
        int re;
        for (i=0; i<nums.size()-2; i++){
            j=i+1; k=nums.size()-1;
            while (j < k){
                int sum = nums[i]+nums[j]+nums[k];
                if (sum > target){
                    if (sum - target < min){
                        min = sum - target;
                        re = sum;
                    }
                    k--;
                }else if (sum < target){
                    if (target - sum < min){
                        min = target-sum;
                        re = sum;
                    }
                    j++;
                }else
                    return sum;
            }
        }
        return re;
    }
};

int main() {
    vector<int> v = {};
    Solution s;
    cout<<s.threeSumClosest(v, 1)<<endl;
    return 0;
}