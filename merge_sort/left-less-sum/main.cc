#include <iostream>
#include <vector>

using namespace std;


class Solution {
private:
  int merge(std::vector<int>&nums, int l, int r, int l2, int r2) {
    int i=l; int j=l2;
    int result = 0;
    std::vector<int> tmpNums;
    while (i<=r && j<=r2) {
      if (nums[i] < nums[j]) {
        result += nums[i] * (r2-j+1);
        tmpNums.push_back(nums[i]);
        i++;
        continue;
      } else if (nums[i] == nums[j]){
        tmpNums.push_back(nums[j]);
        j++;
        continue;
      } else {
        tmpNums.push_back(nums[j]);
        j++;
        continue;
      }
    }

    while (i<=r) {
      tmpNums.push_back(nums[i++]);
    }
    while (j<=r2) {
      tmpNums.push_back(nums[j++]);
    }
    for (int k=l; k<=r2; k++) {
      nums[k] = tmpNums[k-l];
    }
    return result;
  }
  int rawLeftLessSum(std::vector<int>& nums, int l, int r) {
    if (l >= r) return 0;
    if (l == r-1) {
      if (nums[l] > nums[r]) {
        swap(nums[l], nums[r]);
        return 0;
      }
      return nums[l]<nums[r] ? nums[l] : 0;
    }

    int mid = l + (r - l) / 2;
    int lResult = rawLeftLessSum(nums, l, mid);
    int rResult = rawLeftLessSum(nums, mid+1, r);
    int result = merge(nums, l, mid, mid+1, r);
    return lResult + rResult + result;
  }

public:
  int leftLessSum(std::vector<int>& nums) {
    return rawLeftLessSum(nums, 0, nums.size()-1); 
  }
};

int main() {
  Solution s;
  std::vector<int> nums;
  int c;
  while (cin>>c) {
    if (c == 'q') break;
    nums.push_back(c);
  }
  std::cout<<s.leftLessSum(nums)<<std::endl;
  for (auto n : nums) {
    std::cout<<n<<" ";
  }
  std::cout<<std::endl;
  return 0;
}
