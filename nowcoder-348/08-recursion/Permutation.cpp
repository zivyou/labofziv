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
public:
  vector<string> permutation(string str) {
    vector<string> result;
    process(result, str, "");
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