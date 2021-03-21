#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int> > result;
public:
    void dfs(vector<int> &remain, int remainIndex, vector<int> &temp){
        // cout<<"remain = [";
        // for (int i=0; i<=remainIndex; i++)
        //     cout<<remain[i]<<", ";
        // cout<<"    temp = [";
        // for (int i=0; i<temp.size(); i++)
        //     cout<<temp[i]<<", ";
        // cout<<endl;
        if (remainIndex < 0){
            result.push_back(temp);
            return;
        }
        int elem = remain[remainIndex];
        int size=temp.size();
        for (int i=0; i<=size;i++){
            vector<int> newTemp = temp;
            newTemp.insert(newTemp.begin()+i, elem);
            dfs(remain, remainIndex-1, newTemp);
        }
    }
    vector<vector<int> > permute(vector<int>& nums) {
        vector<int> temp;
        dfs(nums, nums.size()-1, temp);
        return result;
    }
};

int main(){
    vector<int> v={1, 2, 3, 4};
    // v.insert(v.begin()+3, 0);
    // for (int i=0; i<v.size(); i++)
    //     cout<<v[i]<<" ";
    // cout<<endl;
    Solution s;
    vector<vector<int> > result;
    result = s.permute(v);
    for (int i=0; i<result.size(); i++){
        for (int j=0; j<result[i].size(); j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}