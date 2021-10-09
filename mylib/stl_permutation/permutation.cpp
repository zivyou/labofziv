#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * STL中就带有全排列的工具函数，就离谱
 * @return
 */

class Solution {
public:
  void myPermutation(vector<int> tmpRe, vector<int> data, vector<vector<int>>& results) {
    if (!data.size()) {
      results.push_back(tmpRe);
      return;
    }

    for (int i=0; i<data.size(); i++) {
      vector<int> tmp(tmpRe);
      tmp.push_back(data[i]);
      vector<int> tmpData(data);
      tmpData.erase(tmpData.begin()+i);
      myPermutation(tmp, tmpData, results);
    }
  }
};

int main() {
  vector<int> array = {3, 5, 2, 9, 8, 1};
  sort(array.begin(), array.end());
  do {
    for (auto elem : array) {
      cout<<elem<<" ";
    }
    cout<<endl;
  } while (next_permutation(array.begin(), array.end()));

  cout<<"============================================"<<endl;
  vector<int> array2 = {3, 5, 2};
  Solution s;
  vector<vector<int>> results;
  vector<int> tmpRe;
  s.myPermutation(tmpRe, array2, results);
  for (auto v : results) {
    for (auto elem : v) {
      cout<<elem<<" ";
    }
    cout<<endl;
  }
}