#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool validTree(int n, vector<vector<int>>& edges) {
        bool map[n+1];
        for (int i=0; i<=n; i++){
            map[i] = false;
        }
        for (auto v : edges){
            if (map[v[1]]){
                return false;
            }
            map[v[0]] = true;

            map[v[1]] = true;
        }

        return true;
    }
};

int main(){
    return 0;
}