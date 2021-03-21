#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int> > & edges) {
        if (n == 0)
            return vector<int>();
        if (n == 1){
            vector<int> v = {0};
            return v;
        }
        int re = 0;
        int count[n];
        for (int i=0; i<n; i++)
            count[i] = 0;
        for (auto edge :edges){
            count[edge[0]]++;
            count[edge[1]]++;
        }
        
        int nn = n;
        while (nn > 2){
            vector<int> deleted;
            for (auto edge : edges){
                if (count[edge[0]] == 1 && count[edge[1]] != -1){
                    count[edge[0]] = -1;
                    deleted.push_back(edge[1]);
                }

                if (count[edge[1]] == 1 && count[edge[0]] != -1){
                    count[edge[1]] = -1;
                    deleted.push_back(edge[0]);
                }
            }
            //cout<<"leaves.size() = "<<leaves.size()<<endl;
            nn = nn-deleted.size();
            for (auto v : deleted){
                count[v]--;
            }
        }

        vector<int> ret;
        for (int i=0; i<n; i++){
            if (count[i] > -1)
                ret.push_back(i);
        }

        return ret;
    }
};




int main(){
    vector<vector<int>> data = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    Solution s;
    vector<int> v = s.findMinHeightTrees(6, data);
    for (auto num : v){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}