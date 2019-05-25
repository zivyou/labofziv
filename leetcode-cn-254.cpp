#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<int > >& re, int n, int begin, vector<int>& tmpRe){
        if (n == 1 ){
            if (tmpRe.size() > 1)
                re.push_back(tmpRe);
            return;
        }
        for (int i=begin; i<=n; i++){
            if (n % i == 0){
                tmpRe.push_back(i);
                dfs(re, n/i, i, tmpRe);
                tmpRe.pop_back();
            }
        }
    }
    vector<vector<int> > getFactors(int n) {
        vector<vector<int> > re;
        vector<int> tmpRe;
        int begin = 2;
        dfs(re, n, begin, tmpRe);
        return re;
    }
};

int main(){
    Solution s;
    vector<vector<int> > re = s.getFactors(12);
    for (int i=0; i<re.size(); i++){
        for (int j=0; j<re[i].size(); j++)
            cout<<re[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}