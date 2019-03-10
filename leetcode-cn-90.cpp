#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int find(vector<vector<int> > data, vector<int> v){
        for (int i=0; i<data.size(); i++){
            if (data[i].size() != v.size())
                continue;
            sort(data[i].begin(), data[i].end());
            sort(v.begin(), v.end());
            int j;
            for (j=0; j<data[i].size(); j++)
                if (data[i][j] != v[j])
                    break;
            if (j == data[i].size())
                return 1;
        }
        return 0;
    }
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > re;
        re.push_back(vector<int>());
        for (int i=0; i<nums.size(); i++){
            vector<vector<int> > newRe(re);
            for (int j=re.size()-1; j>=0; j--){
                vector<int> v = re[j];
                v.push_back(nums[i]);
                if (!find(newRe, v))
                    newRe.push_back(v);
            }
            re = newRe;
        }
        return re;
    }
};

int main(){
    vector<int> v({1,2,2});
    Solution s;
    vector<vector<int> > re = s.subsetsWithDup(v);
    for (int i=0; i<re.size(); i++){
        for (int j=0; j<re[i].size(); j++)
            cout<<re[i][j]<<" ";
        cout<<endl;
    }
}