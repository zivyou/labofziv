#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

class Solution {
private:
    map<int, int> count;
public:
    void wiggleSort(vector<int>& nums) {
        std::sort(nums.begin(), nums.end() );
        if (nums.size() <= 2) return;
        auto mid = (nums.size()+1) / 2;
        for (auto & i : nums) count[i]++;
        int target = -1;
        for (const auto & t : count) {
            if (t.second >= mid) {
                target = t.first;
                break;;
            }
        }
        if (target > 0) {
            auto firstAt = find(nums.begin(), nums.end(), target);
            auto preCount = (int)(firstAt - nums.begin());
            printf("firstAt: %d， target: %d \n", firstAt-nums.begin(), target);
            if (firstAt != nums.end()) {
                nums.insert(nums.end(), nums.begin(), nums.begin()+count[target]-mid);
                nums.erase(nums.begin(), nums.begin()+count[target]-mid);
            }
        }

        for (int i=0; i<nums.size()-1 && nums[i+1]<nums[mid]; i++) {
            if (nums[i] <= nums[i+1]) {
                auto x = nums[mid];
                nums.erase(nums.begin()+mid);
                nums.insert(nums.begin()+i+1, x);
                mid++;
            }
        }
    }
};

int main() {
    vector<int> v = {3, 5, 5,5,5,6,6,6};
    Solution s;
    s.wiggleSort(v);
    for (const auto & n : v) {
        printf("%d ", n);
    }
    printf("\n");
    return 0;
}