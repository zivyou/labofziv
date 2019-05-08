#include <iostream>
#include "../mylib/mylib.h"

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int height = matrix.size();
        if (height <= 0)
            return 0;
        int width = matrix[0].size();
        if (width <= 0)
            return 0;

        int re = 0;

        for (int i=0; i<height; i++){
            for (int j=0; j<width; j++){
                int k=0;
                if (matrix[i][j]){
                    while (i+k < height && j+k < width){
                        for (int ii=i; ii<=i+k; ii++)
                            if (matrix[ii][j] == 0)
                                goto out;
                        for (int jj=j; jj<=j+k; jj++)
                            if (matrix[i][jj] == 0)
                                goto out;
                        k++;
                    }
                }
            out:
                if (k > re)
                    re = k;
            }
        }

        return re;
    }
};

int main()
{
    Solution s;
    char a[] = {'1','0','1','0','0','1','0','1','1','1','1','1','1','1','1','1','0','0','1','0'};
    vector<vector<char> > v = matrixToVector(a, 4, 4);
    cout<<s.maximalSquare(v)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
