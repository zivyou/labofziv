#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

  int process(string str, int i) {
    if (str.length() <= i) return 1;
    if (str[i] == '0') return 0;
    if (str[i] == '1') {
      int cnt1 = process(str, i+1);
      int cnt2 = 0;
      if (i+2 < str.length()) {
        cnt2 = process(str, i+2);
      }
      return cnt1+cnt2;
    }

    if (str[i] == '2') {
      int cnt1 = process(str, i+1);
      int cnt2 = 0;
      if (i+2 < str.length() && str[i+1] <= '6' && str[i+1] >= '0') {
        cnt2 = process(str, i+2);
      }
      return cnt1 + cnt2;
    }
    return process(str, i+1);
  }

  int numberStringToString(string str) {
    return process(str, 0);
  }
};

int main() {
  Solution s;
  cout<<s.numberStringToString("893451892374")<<endl;
  return 0;
}