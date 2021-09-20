//
// Created by zivyou on 2021/9/19.
//

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    int len = s.length();
    vector<int> dp(len, 0);
    int i=0; int max = 0;
    for (i=1; i<len; i++){
      if (s[i] == ')'){
        int j = i-dp[i-1]-1;
        if (s[j] == '('){
          dp[i] = dp[i-1]+2;
          if (j-1 >=0 && s[j-1] == ')'){
            dp[i] = dp[i] + dp[j-1];
          }
        }
      }
      if (dp[i] > max)
        max = dp[i];
    }
    return max;
  }
};

int main() {
  return 0;
}