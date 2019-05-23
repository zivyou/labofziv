#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
    int factorial[10];
    string getPermutation(int n, int k) {
        string re;
        factorial[0] = 1;
        for (int i=1; i<=9; i++){
            factorial[i] = i*factorial[i-1];
        }

        int bitWidth = 0;
        for (int i=1; i<=9; i++){
            if (factorial[i] > k){
                bitWidth = i;
                break;
            }
        }

        if (bitWidth == 0)
            return "";
        
        int last = 1;
        // the last $bitWidth number limit to [last+1, n]
        for (last=1; last<=n-bitWidth; begin++)
            re = re+std::to_string(begin);
        int remain = k - begin*();
        re = re + std::to_string();
    }
    */

    void dfs(vector<vector<int> > &re, vector<int> &nums, int end, vector<int> &tmpRe, int count){
        if (re.size() > count)
            return;
        if (end < 0){
            re.push_back(tmpRe);
            return;
        }

        int elem = nums[end];
        for (int i=0; i<=tmpRe.size(); i++){
            vector<int> newTmpRe = tmpRe;
            newTmpRe.insert(newTmpRe.begin()+i, nums[end]);
            dfs(re, nums, end-1, newTmpRe, count);
        }
    }

    string getPermutation(int n, int k) {
        vector<vector<int> > re;
        vector<int> nums;
        vector<int> tmpRe;
        for (int i=1; i<=n; i++)
            nums.push_back(i);
        
        dfs(re, nums, nums.size()-1, tmpRe, k);

        for (int i=0; i<re.size(); i++){
            for (int j=0; j<re[i].size(); j++)
                cout<<re[i][j]<<" ";
            cout<<endl;
        }
        
        return "";
    }
};

int main(){
    Solution s;
    s.getPermutation(3, 4);
    return 0;
}