#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Solution {
private:
  vector<int> origin;
  vector<int> current;
public:
    Solution(vector<int>& nums) {
      origin.assign(nums.begin(), nums.end());
      current.assign(nums.begin(), nums.end());
      srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
      return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
      vector<int> re;
      while (current.size() > 0) {
        int index = rand() % current.size();
        re.push_back(current[index]);
        current.erase(current.begin() + index);
      }
      current.assign(origin.begin(), origin.end());
      return re;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main() {

}