#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:

public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0; unsigned int size = nums.size();
        for (int n : nums) sum += n;
        int* F = new int[size];
        std::fill(F, F+size-1, 0);
        for (unsigned int i=0; i<size; i++) {
            F[0] += nums[i]*i;
        }
        int max = F[0];
        for (unsigned int i=1; i<size; i++) {
            F[i] = F[i-1] + sum - size*nums[size-i];
            max = std::max(max, F[i]);
        }
        delete[] F;
        return max;
    }
};
/*
[0, 1, 2, 3] num = [x1]
[1, 2, 3, 0]       [x2]
[2, 3, 0, 1]       [x3]
[3, 0, 1, 2]       [x4]
*/


int main() {
    Solution s;
    std::cout<<s.maxRotateFunction(*new vector<int> ({100}))<<std::endl;
    return 0;
}