#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findFather(int *set, int i){
        if (set[i] == i)
            return i;
        set[i] = findFather(set, set[i]);
        return set[i];
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        //sort(edges.begin(), edges.end());
        int fathers[n+1];
        for (int i=0; i<n; i++)
            fathers[i] = i;
        
        for (auto edge : edges){
            int a = edge[0];
            int b = edge[1];
            int f1 = findFather(fathers, a);
            int f2 = findFather(fathers, b);
            int f = f1 < f2 ? f1 : f2;
            fathers[a] = f;
            fathers[b] = f;
            
            if (f1 != f){
                fathers[f1] = f;
            }else{
                fathers[f2] = f;
            }
        }

        int re = 0;
        for (int i=0; i<n; i++){
            cout<<fathers[i]<<" ";
            if (fathers[i] == i)
                re++;
        }
        cout<<endl;
        return re;
    }
};

int main(){
    vector<vector<int>> data = {{5,8},{3,5},{1,9},{4,5},{0,2},{1,9},{7,8},{4,9}};
    Solution s;
    cout<<s.countComponents(10, data)<<endl;
    return 0;
}