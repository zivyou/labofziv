#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size();
        int n = B[0].size();
        vector<vector<int> > re(m , vector<int>(n, 0));
        if (m <= 0 || n<=0)
            return re;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                int t = 0;
                for (int k=0; k<A[i].size(); k++){
                    if (A[i][k] == 0)
                        continue;
                    t = t+A[i][k]*B[k][j];
                }
                re[i][j] = t;
            }
        }
        return re;
    }
};


int main(){
    return 0;
}