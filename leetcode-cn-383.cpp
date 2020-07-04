#include <iostream>
#include <map>

using namespace std;

class Solution {
private:
  map<char, int> m;
public:
    bool canConstruct(string ransomNote, string magazine) {
      for (auto c : magazine) {
        if (m.find(c) == m.end()) {
          m[c] = 1;
        } else {
          m[c]++;
        }
      }

      for (auto c : ransomNote) {
        if (m.find(c) == m.end()) {
          return false;
        } else {
          m[c]--;
          if (m[c] < 0) return false;
        }
      }
      return true;
    }
};

int main() {
  Solution s;
  cout<<s.canConstruct("aa", "ab")<<endl;
  return 0;
}