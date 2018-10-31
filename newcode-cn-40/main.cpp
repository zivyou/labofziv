#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > re;
    vector<int> data;

    static int vectorCmp(vector<int>& a, vector<int>& b){
        for (int i=0; i<a.size() && i<b.size(); i++){
            if (a[i] < b[i])
                return -1;
            else if (a[i]>b[i])
                return 1;
            else
                continue;
        }

        if (a.size() < b.size()) return -1;
        else if(a.size() == b.size()) return 0;
        else return 1;
    }
    void vectorInsert(vector<int> &tmp){
        if (re.size() == 0){
            re.push_back(tmp);
            return;
        }
        int i;
        for ( i=re.size()-1; i>=0; i--){
            if (vectorCmp(tmp, re[i]) == 0)
                return;
        }

        re.push_back(tmp);
    }

    void dfs(int target, int start, vector<int>& output){
        if (target<0){
            return;
        }
        if (target == 0){
            vector<int> tmp = output;
            sort(tmp.begin(), tmp.end());
            vectorInsert(tmp);
            return;
        }

        for (int i=start; i<data.size(); i++){
            output.push_back(data[i]);
            dfs(target-data[i], i+1, output);
            output.pop_back();
        }
    }
    static int cmp(int & a, int& b){
        if (a > b)
            return 1;
        else
            return 0;
    }
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        data = candidates;
        sort(data.begin(), data.end(), Solution::cmp);
        vector<int> output;
        dfs(target, 0, output);

        return re;
    }
};

int main()
{
    vector<int> input = {4,4,2,1,4,2,2,1,3};
    Solution s;
    vector<vector<int> > re = s.combinationSum2(input, 6);

    for (int i=0; i<re.size(); i++){
        for (int j=0; j<re[i].size(); j++)
            cout<<re[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
