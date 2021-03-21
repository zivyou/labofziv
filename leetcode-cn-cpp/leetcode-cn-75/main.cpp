#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int sum = 0;
        int x = 0;
        int y = 0;
        int z = 0;
        for (int i=0; i<nums.size(); i++){
            sum = sum + nums[i];
            if (nums[i] == 1)
                y++;
        }

        z = (sum - y) / 2;
        x = nums.size() - z - y;

        for (int i=0; i<nums.size(); i++){
            if (i < x)
                nums[i] = 0;
            else if (i < y+x)
                nums[i] = 1;
            else
                nums[i] = 2;
        }

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}