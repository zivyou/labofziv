//
// Created by zivyou on 2021/3/11.
//

/**
 * 字符串全排列
 * abc -> [abc, acb, bac, bca, cab, cba]
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
class Permutation {
private:
  // 假设字符串没有重复字符的全排列
  void process(vector<string>& result, string str, string tmpRe) {
    if (str.length() == 0) {
      result.push_back(tmpRe);
      return;
    }

    for (int i=0; i<str.length(); i++) {
      string pick = tmpRe + (str[i]);
      string next = str;
      next.erase(next.begin()+i);
      process(result, next, pick);
    }
  }

  // 字符串有重复字符的全排列
  void process2(vector<string>& result, string str, string tmpRe) {
    if (str.length() == 0) {
      result.push_back(tmpRe);
      return;
    }

    unordered_set<char> visited;
    for (int i=0; i<str.length(); i++) {
      if (visited.find(str[i]) != visited.end()) {
        continue;
      }

      string pick = tmpRe + str[i];
      string next = str;
      next.erase(next.begin()+i);
      visited.insert(str[i]);
      process2(result, next, pick);
    }
  }
public:
  vector<string> permutation(string str) {
    vector<string> result;
    //process(result, str, "");
    process2(result, str, "");
    return result;
  }
};

int main() {
  Permutation p;
  vector<string> re = p.permutation("aac");
  for (string s : re) {
    cout<<s<<endl;
  }
  return 0;
}