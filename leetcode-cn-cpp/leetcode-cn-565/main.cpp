#include <climits>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int* setIds;
public:
    int getSetId(vector<int>& nums, int i) {
        if (setIds[nums[i]] >= 0) return setIds[nums[i]];
        unordered_set<int> visited;
        while (visited.find(nums[i]) == visited.end()) {
            visited.insert(nums[i]);
            i = nums[i];
        }
        for (auto& e : visited) {
            setIds[e] = i;
        }
        return setIds[i];
    }

    int arrayNesting(vector<int>& nums) {
        setIds = new int[nums.size()];
        // std::copy(nums.begin(), nums.end(), setIds);
        std::fill_n(setIds, nums.size(), -1);
        unordered_map<int, int> counts;
        for (int i=0; i<nums.size(); i++) {
            counts[getSetId(nums, i)]++;
        }
        int max = INT_MIN;
        for (auto& pair : counts) {
            if (pair.second > max) max = pair.second;
        }
        delete[] setIds;
        return max;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> v = {5,4,0,3,1,6,2};
    printf("%d\n", s.arrayNesting(v));
}
