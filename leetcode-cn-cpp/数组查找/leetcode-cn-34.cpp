#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int begin = 0; int end = nums.size()-1;
    int mid;
    if (nums.size() <= 0){
      vector<int> v;
      v.push_back(-1);
      v.push_back(-1);
      return v;
    }
    while (begin < end){
      mid = (begin+end)/2;
      if (nums[mid] == target)
        break;
      else if (nums[mid] > target)
        end = mid-1;
      else
        begin = mid+1;
    }

    if (nums[(begin+end)/2] != target){
      vector<int> v;
      v.push_back(-1);
      v.push_back(-1);
      return v;
    }

    mid = (begin+end)/2;
    int i=0; int j=0;
    while (true){
      if (mid-i>=0 && nums[mid] == nums[mid-i])
        i++;
      else
        break;
    }

    while (true){
      if (mid+j<nums.size() && nums[mid] == nums[mid+j])
        j++;
      else
        break;
    }

    vector<int> v;
    v.push_back(mid-i+1);
    v.push_back(mid+j-1);
    return v;
  }
};
