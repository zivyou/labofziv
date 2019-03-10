#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        if (n <= 1)
            return;
        for (int i=0; i<n/2; i++){
            //now the left-top corner index is [i][i]
            //cout<<"[i][i]="<<"["<<i<<"]["<<i<<"]"<<endl;
            for (int j=i; j<(n-i-1); j++){
                int t = matrix[i][j];
                // left to top
                matrix[i][j] = matrix[n-j-1][i];
                //bottom to left
                //matrix[n-j-1][i] = matrix[i][n-j-1];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                //right to bottom
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                // top to right;
                matrix[j][n-i-1] = t;
            }

        }
    }
};

int main(){
    int a[][5] = {{1,2,3, 4, 5},{6,7, 8, 9, 10},{11, 12, 13, 14, 15},{16,17,18,19,20},{21,22,23,24,25}};
    vector<vector<int> > matrix; 
    for (int i=0; i<5; i++){
        vector<int> v(a[i], a[i]+5);
        matrix.push_back(v);
    }
    Solution s;
    s.rotate(matrix);
    for (int i=0; i<matrix.size(); i++){
        for (int j=0; j<matrix[i].size(); j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}