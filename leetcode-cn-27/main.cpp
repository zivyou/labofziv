#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int i, j;
        for (i=0; i<length; i++){
            if (nums[i] == val){
                length--;
                for (j=i; j<nums.size()-1; j++)
                    nums[j] = nums[j+1];
                i--;
            }
        }

        return length;
    }
};

int main() {
    vector<int> v={2, 2, 1, 3, 2};
    Solution s;
    int re = s.removeElement(v, 2);
    for (int i=0; i<re; i++)
        cout<<v[i]<<", ";
    cout<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}