/*
 *
 * 将整数n分成k份，且每份不能为空，任意两个方案不能相同(不考虑顺序)。
例如：n=7，k=3，下面三种分法被认为是相同的。
1，1，5;
1，5，1;
5，1，1;
问有多少种不同的分法。
 */

#include <iostream>
#include <vector>

using namespace std;

#define printVector(v)  \
do { \
  for (int i=0; i<v.size(); i++) { \
    cout<<v[i]<<' '; \
  } \
  cout<<endl;\
} while (false)

class Solution {
private:
  static bool equal(vector<int> a, vector<int> b) {
    if (a.size() != b.size()) return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i=0; i<a.size(); i++) {
      if (a[i] != b[i]) return false;
    }
    return true;
  }
  static bool exist(const vector<vector<int>>& data, const vector<int>& elem) {
    for (const auto& v : data) {
      if ( equal(v, elem)) return true;
    }
    return false;
  }
public:
  void process(int N, int k, vector<vector<int>>& results, vector<int> tmpRe) {
    if (k == 0 && N != 0) return;
    if (k == 0 && N == 0) {
      if (!exist(results, tmpRe)) {
        results.push_back(tmpRe);
      }
      return;
    }
    if (N <= 1) return;
    for (int i=1; i<=N; i++) {
      tmpRe.push_back(i);
      process(N-i, k-1, results, tmpRe);
      tmpRe.pop_back();
    }
  }
};

int main() {
  int N; int k;
  cin>>N>>k;
  Solution s;
  vector<vector<int>> results;
  vector<int> tmpRe;
  s.process(N, k, results, tmpRe);
  cout<<results.size()<<endl;

//  for (const auto & v: results) {
//    printVector(v);
//  }
  return 0;
}
