#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
  map<int, int> m;
public:
    int combinationSum4(vector<int>& nums, int target) {
      unsigned int re[target+1];
      for (int i=0; i<=target; i++) re[i] = 0;
      int cur = 0;
      while (cur ++ < target) {
        bool found = false;
        for (auto elem: nums) {
          if (elem <= cur) {
            re[cur] += re[cur-elem];
            if (elem == cur) found = true;
          }
        }
        if (found) re[cur]++;
      }
      return re[target];
    }
};

int main() {
  Solution s;
  vector<int> data = {3, 33, 333};
  int target = 10000;
  cout<<s.combinationSum4(data, target)<<endl;
  return 0;
}