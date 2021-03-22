#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &re, vector<int> &nums, vector<int> &tmpRe, int* used){
        if (tmpRe.size() == nums.size()){
            re.push_back(tmpRe);
            return;
        }


        for (int i=0; i<nums.size(); i++){
            if (used[i])
                continue;
            if (i-1>=0 && nums[i] == nums[i-1] && !used[i-1])
                continue;
            tmpRe.push_back(nums[i]);
            used[i] = 1;
            dfs(re, nums, tmpRe, used);
            tmpRe.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> re;
        vector<int> tmpRe;
        int used[nums.size()+1];
        for (int i=0; i<nums.size()+1; i++)
            used[i] = 0;
        sort(nums.begin(), nums.end());
        dfs(re, nums, tmpRe, used);
        return re;
    }
};

int main(){
    Solution s;
    vector<int> nums({1,1, 3});
    vector<vector<int>> re = s.permuteUnique(nums);
    for (int i=0; i<re.size(); i++){
        for (int j=0; j<re[i].size(); j++)
            cout<<re[i][j]<<" ";

        cout<<endl;
    }
}