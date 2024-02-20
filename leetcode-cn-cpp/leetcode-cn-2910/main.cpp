#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (const auto& n : nums) {
            counts[n]++;
        }

    }
};

int main(int argc, char* argv[]) {

}
