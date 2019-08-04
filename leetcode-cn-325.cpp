#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.size() <= 0)
            return 0;
        int sum = 0;
        map<int, vector<int>> m;
        vector<int> tv = {0};
        m[0] = tv;
        for (int i=1; i<=nums.size(); i++){
            sum = sum + nums[i-1];
            if (m.find(sum) == m.end()){
                vector<int> v;
                v.push_back(i);
                m[sum] = v;
            }else{
                m[sum].push_back(i);
            }
            
        }
        int re = 0;
        for (auto pair : m){
            cout<<pair.first<<" ";
            vector<int> begin = pair.second;
            if (m.find(pair.first+k) != m.end()){
                vector<int> end = m[pair.first+k];
                for (int i=0; i<begin.size(); i++){
                    for (int j=0; j<end.size(); j++){
                        if (begin[i] - begin[j] > re)
                            re = begin[i] - begin[j] ;
                        if (begin[j] - begin[i] > re ){
                            re = begin[j] - begin[i];
                        }
                    }
                }
            }
        }
        cout<<endl;
        return re;
    }
};
/*
class Solution {
public:
    void dfs(vector<vector<int>> & re, vector<int> &nums, int k, vector<int>& tmpRe, int begin){
        if (begin == nums.size()){
            if (k != 0)
                return;
            else{
                re.push_back(tmpRe);
            }
            return;
        }

        for (int i=begin; i<nums.size(); i++){
            tmpRe.push_back(nums[i]);
            dfs(re, nums, k-nums[i], tmpRe, i+1);
            tmpRe.pop_back();
        }

    }
    int maxSubArrayLen(vector<int>& nums, int k) {
        vector<vector<int>> re;
        vector<int> tmpRe;
        int begin = 0;
        dfs(re, nums, k, tmpRe, begin);
        int max = 0;
        for (auto v : re){
            if (v.size() > max)
                max = v.size();
        }
        return max;
    }
};
*/

int main(){
    vector<int> v = {1, -1, 5, -2, 3};
    Solution s;
    cout<<s.maxSubArrayLen(v, 3)<<endl;;
    return 0;
}