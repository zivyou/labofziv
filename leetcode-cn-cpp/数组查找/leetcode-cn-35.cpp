#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int i = 0;
    if (nums.size() == 0){
      nums.push_back(target);
      return 0;
    }

    if (nums.size() == 1){
      if (nums[0] > target){
        nums.insert(nums.begin(), target);
        return 0;
      }else if (nums[0] == target){
        return 0;
      }else {
        nums.push_back(target);
        return 1;
      }
    }

    vector<int>::iterator iter = nums.begin();

    for (int i=0; iter != nums.end(); iter++, i++){
      if (*iter<target){
        if (iter+1 == nums.end()){
          nums.push_back(target);
          return i+1;
        }
        if (*(iter+1) > target){
          nums.insert(iter+1, target);
          return i+1;
        }
        if (*(iter+1) == target){
          return i+1;
        }
        if (*(iter+1) < target)
          continue;
      }else if (*iter == target){
        return i;
      }else{
        nums.insert(iter, target);
        return i;
      }
    }

  }
};