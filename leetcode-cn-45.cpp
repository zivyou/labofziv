#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> cnt(nums.size(), 0);
        vector<int> path(nums.size(), 0);
        for (int i=1; i<nums.size(); i++){
            if (path[i-1]+nums[path[i-1]] >= i){
                if (i == 1)
                    cnt[i] = 1;
                else
                    cnt[i] = cnt[i-1];
                path[i] = path[i-1];
            }else{
                int j=path[i-1];
                while (1){
                    if (nums[j]+j >= i){
                        path[i] = j;
                        cnt[i] = cnt[j]+1;
                        break;
                    }
                    j++;
                }
            }
        }
        // for (int i=0; i<path.size(); i++)
        //     cout<<path[i]<<" ";
        // cout<<endl;
        // for (int i=0; i<cnt.size(); i++)
        //     cout<<cnt[i]<<" ";
        // cout<<endl;
        return cnt[nums.size()-1];
    }
};

int main(){
    vector<int> v={1};
    Solution s;
    cout<<s.jump(v)<<endl;
    return 0;
}