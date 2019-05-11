#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void rawCombinationSum3(vector<vector<int>> &re, vector<int> tempRe, int k, int n, int begin){
        if (begin > n)
            return;
        if (begin > 9)
            return;
        if (k < 1)
            return;
        if (k == 1){
            int remain = n;
            if (find(tempRe.begin(), tempRe.end(), remain) == tempRe.end()){
                if (remain > 0 && remain <= 9) {
                    tempRe.push_back(remain);
                    re.push_back(tempRe);
                }
            }
            return;
        }

        for (int i=begin; i<=9; i++){
            tempRe.push_back(i);
            rawCombinationSum3(re, tempRe, k-1, n-i, i+1);
            tempRe.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> re;
        vector<int> tempRe;
        rawCombinationSum3(re, tempRe, k, n, 1);
        return re;
    }
};

int main() {
    Solution s;
    vector<vector<int>> re;
    re = s.combinationSum3(2, 17);
    for (int i=0; i<re.size(); i++){
        for (int j=0; j<re[i].size(); j++)
            cout<<re[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}