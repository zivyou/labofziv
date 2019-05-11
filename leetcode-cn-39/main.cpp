#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> data;
    vector<vector<int>> re;
    void dfs(int target, int start, vector<int>& output){
        if (target < 0) return;
        if (target == 0) {
            vector<int> tmp = output;
            sort(tmp.begin(), tmp.end());
            re.push_back(tmp);
            return;
        }

        for (int i=start; i<data.size(); i++){
            output.push_back(data[i]);
            dfs(target-data[i], i, output);
            output.pop_back();
        }
    }
    static int cmp(int &a, int &b){
        if (a > b)
            return 1;
        else
            return 0;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        data = candidates;
        sort(data.begin(), data.end(), Solution::cmp);
        vector<int> output;
        dfs(target, 0, output);
        return re;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> candidates = {2, 3, 5};
    vector<vector<int>> re;
    Solution s;
    re = s.combinationSum(candidates, 8);
    for (int i=0; i<re.size(); i++){
        for (int j=0; j<re[i].size(); j++){
            cout<<re[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}