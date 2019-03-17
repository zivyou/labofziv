#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int circle(vector<int>& gas, vector<int>& cost, int origin, int cur, int remainGas){
        if (remainGas < 0)
            return -1;
        if (origin == cur)
            return cur;

        remainGas = remainGas + gas[cur];
        remainGas = remainGas - cost[cur];
        if (remainGas < 0)
            return -1;
        int next = (cur + 1) % gas.size();
        return circle(gas, cost, origin, next, remainGas);
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() <= 0)
            return 0;
        for (int i=0; i<cost.size(); i++){
            int pos = circle(gas, cost, i, (i+1)%gas.size(), gas[i]-cost[i]);
            if (pos >= 0)
                return i;
        }

        return -1;
    }
};

int main()
{
    vector<int> gas({1,2,3,4,5});
    vector<int> cost({3,4,5,1,2});
    Solution s;
    cout<<s.canCompleteCircuit(gas, cost)<<endl;
    return 0;
}
