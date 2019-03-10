#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void createCombine(vector<vector<int> >& re, vector<int> data, int k, vector<int> path){
        if (k == 0)
            return;
        if (k == 1){
            for(int i=0; i<data.size(); i++){
                vector<int> newPath = path;
                newPath.push_back(data[i]);
                re.push_back(newPath);
            }
            return;
        }
        if (data.size() < k)
            return;

        int t = data[0];
        data.erase(data.begin());
        createCombine(re, data, k, path);
        path.push_back(t);
        createCombine(re, data, k-1, path);
    }
    vector<vector<int> > combine(int n, int k) {
        vector<int> origin;
        for (int i=1; i<=n ;i++)
            origin.push_back(i);
        vector<int> path;
        vector<vector<int> > re;
        createCombine(re, origin, k, path);
        return re;
    }
};

int main(){
    Solution s;
    vector<vector<int> > re = s.combine(4, 2);
    for (int i=0; i<re.size(); i++){
        for (int j=0; j<re[0].size(); j++){
            cout<<re[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}