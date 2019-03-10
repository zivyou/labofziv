#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void getSubsets(vector<vector<int> >& re, vector<int> data, int length, vector<int>  path){
        if (data.size() < length)
            return;
        if (data.size() == length){
            for (int i=0; i<data.size(); i++)
                path.push_back(data[i]);
            re.push_back(path);
            return;
        }


        int t = data[0];
        data.erase(data.begin());
        getSubsets(re, data,length, path);
        path.push_back(t);
        getSubsets(re, data, length-1, path);
    }
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > re;
        for (int i=1; i<=nums.size(); i++){
            vector<int> path;
            getSubsets(re, nums, i, path);
        }
        vector<int> t;
        re.push_back(t);
        return re;
    }
};

int main(){
    vector<int> nums({1,2,3});
    Solution s;
    vector<vector<int> > re = s.subsets(nums);
    for (int i=0; i<re.size(); i++){
        for (int j=0; j<re[i].size(); j++){
            cout<<re[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}