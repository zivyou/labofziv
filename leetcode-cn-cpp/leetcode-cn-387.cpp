#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int firstUniqChar(string s) {
    std::map<char, vector<int> > data;
    for (int i=0; i<s.size(); i++) {
      char c = s[i];
      if (data.find(c) == data.end()) {
        vector<int> v = {1, i};
        data[c] = v;
      } else {
        data[c][0]++;
      }
    }

    for (int i=0; i<=s.size(); i++) {
      char c = s[i];
      if (data.find(c) != data.end()) {
        if (data[c][0] == 1) return data[c][1];
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  cout<<s.firstUniqChar("aabbc")<<endl;
  return 0;
}