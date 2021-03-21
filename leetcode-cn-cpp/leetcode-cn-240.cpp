#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int height = matrix.size();
        if (height <= 0)
            return false;
        int width = matrix[0].size();
        if (width <= 0)
            return false;
        int x = 0; int y = width-1;
        while (x < height && y >= 0){
            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] > target){
                y--;
            }else{
                x++;
            }
        }

        return false;
    }
};

int main(){
    return 0;
}