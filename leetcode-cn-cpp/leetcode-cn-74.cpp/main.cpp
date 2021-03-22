#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getValue(vector<vector<int>>& matrix, int pos){
        int m = matrix.size();
        if (m == 0) return matrix[0][pos];
        int n = matrix[0].size();

        int i = pos/n;
        int j = pos%n;
        return matrix[i][j];
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();

        int l = 0; int r = m*(n-1)+m-1;

        while (l <= r){
            int mid = (l+r)/2;
            int value = getValue(matrix, mid);
            if (target == value)
                return true;
            if (value > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return false;
    }
};

int main() {
    vector<vector<int> > matrix;
    matrix.push_back(vector<int>({1,3,5,7}));
    matrix.push_back(vector<int>({10,11,16,20}));
    matrix.push_back(vector<int>({23,30,34,50}));
    Solution s;
    cout<<s.searchMatrix(matrix, 2)<<endl;
    return 0;
}