#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int min(int a, int b){
        if (a > b)
            return b;
        else
            return a;
    }
    int maxArea(vector<int>& height) {
        int max = 0;
        int i=0;
        for (i=0; i<height.size()-1; i++){
            int j=0;
            for (j=i+1; j<height.size(); j++){
                if ((j-i)*min(height[i], height[j]) > max)
                    max = (j-i)*min(height[i], height[j]);
            }
        }

        return max;
    }
};
int main() {
    vector<int> v = {1,8};
    Solution s;
    cout<<s.maxArea(v)<<endl;
    return 0;
}