#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int countLessThan(vector<vector<int>>& matrix, int n) {
    int x = matrix.size()-1;
    int y = 0; int yMax = matrix[0].size() - 1;
    int count = 0;
    while (x >= 0 && y <= yMax) {
      if (matrix[x][y] <= n) {
        count += x + 1;
        y++;
      } else {
        x--;
      }
    }
    return count;
  }

  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int left = matrix[0][0];
    int x = matrix.size() - 1;
    int y = matrix[0].size() - 1;
    int right = matrix[x][y];
    int mid = right + (left - right) / 2; 
    while (left < right) {
      mid = (left + right) / 2;
      int count = countLessThan(matrix, mid);

      if (count >= k) {
        right = mid;
      } else if (count < k) {
        left = mid + 1;
      }
    }
    return right;
  }
};

int main() {
  vector<vector<int> > matrix;
  matrix.push_back(vector<int>({1, 5, 9}));
  matrix.push_back(vector<int>({10, 11, 13}));
  matrix.push_back(vector<int>({12, 13, 15}));
  Solution s;
  cout<<s.kthSmallest(matrix, 8)<<endl;
  return 0;
}