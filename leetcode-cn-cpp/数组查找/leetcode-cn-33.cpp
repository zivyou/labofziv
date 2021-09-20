#include <vector>
#include <iostream>

using namespace std;

class Solution{
public:
  int search(vector<int>& nums, int target) {
    if (nums.size() <= 0) return -1;
    int leftOrRight = target >= nums[0] ? 0 : 1;
    int begin = 0;
    int end = nums.size() - 1;
    while (begin <= end){
      //cout<<"begin="<< begin<<", end="<<end<<endl;
      int mid = (begin+end)/2;
      if (mid == begin || mid == end)
        break;
      int midPos = nums[mid] >= nums[0] ? 0 : 1;
      if (!leftOrRight && !midPos){
        if (nums[mid] > target)
          end = mid;
        else
          begin = mid;
      }

      if (leftOrRight && midPos){
        if (nums[mid] > target)
          end = mid;
        else
          begin = mid;
      }

      if (leftOrRight && !midPos){
        begin = mid;
      }

      if (!leftOrRight && midPos){
        end = mid;
      }
    }
    if (nums[begin] == target)
      return begin;
    if (nums[end] == target)
      return end;
    return -1;
  }
};