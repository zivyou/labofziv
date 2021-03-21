#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        int *re = new int[len+1]();
        int i = 0;
        re[0] = re[1] = 0;
        //re[1] = (cost[1] < re[0]+cost[1]) ? cost[1] : re[0]+cost[1];
        for (i=2; i<=len; i++){
            if (re[i-1]+cost[i-1] < re[i-2]+cost[i-2])
                re[i] = re[i-1] + cost[i-1];
            else
                re[i] = re[i-2] + cost[i-2];
        }
        int value = re[len];
        delete[] re;
        return value;
    }
};

int main() {
    vector<int> cost = {10, 15, 20};
    Solution s;
    cout<<s.minCostClimbingStairs(cost)<<endl;
    return 0;
}