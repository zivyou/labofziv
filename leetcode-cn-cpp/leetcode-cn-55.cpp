#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool result;
    vector<bool> map;
    void dfs(vector<int>& nums, vector<int>& path, int k){
                cout<<"k="<<k<<endl;
        int farest = k+nums[k];
        int numLen = nums.size();
        int pathLen = path.size();
        if (farest >= nums.size()-1){
            result = true;
            return;
        }

        for (int i=k+1; i<=farest && i<nums.size(); i++){
            if (path.size() > 0)
            if (i+nums[i] < path[pathLen-1]+nums[path[pathLen-1]])
                continue;
            if (!map[i])
                continue;
            path.push_back(i);
            dfs(nums, path, i);
            if (result)
                return;
            path.pop_back();
            map[i] = false;
        }
    }

    /*
    bool canJump(vector<int>& nums) {
        result = false;
        vector<int> path;
        map = vector<bool>(nums.size(), true);
        dfs(nums, path, 0);
        return result;
    }
    */

    bool canJump(vector<int>& nums){
        bool reachable[nums.size()];
        for (int i=0; i<nums.size(); i++)
            reachable[i] = false;
        reachable[0] = true;
        for (int i=0; i<nums.size(); i++){
            if (!reachable[i])
                continue;
            for (int j=i; j<=i+nums[i]&& j<nums.size(); j++){
                reachable[j]=true;
            }
        }

        return reachable[nums.size()-1];
    }
};

int main(){
    vector<int> array;
    int n;
    ifstream ins;
    ins.open("data.txt", ios::in);
    while (ins>>n){
        array.push_back(n);
    }
    ins.close();
    Solution s;
    cout<<s.canJump(array)<<endl;
    return 0;
}
