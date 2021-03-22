#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
      if (n <= 1) return n;
      int* re = new int[n+1];
      re[0] = 0;
      for (int i=1; i<=n; i++) {
        int minNum = INT_MAX;
        for (int j=1; j*j<=i; j++) {
          minNum = min(minNum, re[i-j*j]);
        }
        re[i] = minNum+1;
      }
      int result = re[n];
      delete[] re;
      return result;
    }
};

int  main() {
  Solution s;
  cout<<s.numSquares(12)<<endl;
  return 0;
}