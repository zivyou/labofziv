#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int> > sum;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size()==0)
            return;
        sum = matrix;
        for (int i=1; i<matrix[0].size(); i++){
            sum[0][i] = sum[0][i-1]+matrix[0][i];
        }

        for (int i=1; i<matrix.size(); i++){
            sum[i][0] = sum[i-1][0]+matrix[i][0];
        }
        for (int i=1; i<matrix.size(); i++){
            for (int j=1; j<matrix[i].size(); j++){
                int tmp = 0;
                for (int k=0; k<=i; k++){
                    tmp = tmp + matrix[k][j];
                }
                sum[i][j] = sum[i][j-1] + tmp;
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0)
            return sum[row2][col2];
        if (row1 == 0)
            return sum[row2][col2] - sum[row2][col1-1];
        if (col1 == 0)
            return sum[row2][col2] - sum[row1-1][col2];
        
        int r1 = sum[row1-1][col1-1];
        int r2 = sum[row1-1][col2];
        int r3 = sum[row2][col1-1];
        int r4 = sum[row2][col2];
        return r4 - r2 - r3 + r1;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(){
    return 0;
}