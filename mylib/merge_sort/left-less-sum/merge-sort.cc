#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void sort(std::vector<int>& nums) {
      rawSort(nums, 0, nums.size()-1); 
    }
  private:
    void merge(std::vector<int>& nums, int l, int r) {
      std::cout<<"l="<<l<<", r="<<r<<std::endl;
      int i=l; int mid=l+(r-l)/2; int j=mid+1;
      std::vector<int> tmp(r-l+1);
      int k=0;
      while (i<=mid && j<=r) {
        if (nums[i] < nums[j]) {
          tmp[k++] = nums[i++];
        } else {
          tmp[k++] = nums[j++];
        }
      }

      while (i<=mid) tmp[k++] = nums[i++];
      while (j<=r) tmp[k++] = nums[j++];

      for (int ii=l; ii<=r; ii++) {
        nums[ii] = tmp[ii-l];
      }
    }

    void rawSort(std::vector<int>& nums, int l, int r) {
      if (l >= r) {
        return;
      }

      if (l == r-1) {
        if (nums[l] > nums[r]) {
          std::swap(nums[l], nums[r]);
          return;
        }
      }

      int mid = l + (r - l)/2;
      std::cout<<"mid = "<<mid<<std::endl;
      rawSort(nums, l, mid);
      rawSort(nums, mid+1, r);
      merge(nums, l, r);
    }
};

int main() {
  Solution s;
  std::vector<int> nums;
  int i;
  while (cin >> i) {
    if (i == 'q') break;
    nums.push_back(i);
  }
  s.sort(nums);
  for (auto n: nums) {
    std::cout<<n<<" ";
  }
  std::cout<<std::endl;
  return 0;
}
