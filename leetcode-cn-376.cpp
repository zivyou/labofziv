#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() <= 0) return 0;
    int len = nums.size();
    if (len == 1) return 1;
    int up = 1; int down = 1;
    for (int i=1; i<nums.size(); i++) {
      if (nums[i] > nums[i-1]) {
        up = down + 1;
      }

      if (nums[i] < nums[i-1]) {
        down = up + 1;
      }
    }

    return max(up, down);
  }
};

int main() {
  vector<int> data = {1,17,5,10,13,15,10,5,16,8};
  Solution s;
  cout<<s.wiggleMaxLength(data)<<endl;
  return 0;
}