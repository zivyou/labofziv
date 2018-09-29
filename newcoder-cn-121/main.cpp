#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dump(int *a, int n){
        int i=0;
        for (i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
public:
    int maxProfit(vector<int>& prices) {
        int len = (int)prices.size();
        if (len <= 0)
            return 0;
        int *max = new int[len]();
        int *re = new int[len]();


        int i = 0; int max_num = 0;
        max[len-1] = prices.at(len-1);

        for(i=len-2; i>=0; i--){
            if (prices.at(i) > max[i+1]){
                max[i] = prices.at(i);
            }else
                max[i] = max[i+1];
        }

        for (i=0; i<len; i++){
            if (max[i] - prices.at(i) < 0)
                re[i] = 0;
            else
                re[i] = max[i]-prices.at(i);

        }



        max_num = 0;
        for (i=0; i<len; i++)
            if (re[i] > max_num)
                max_num = re[i];

        delete[] max;
        delete[] re;

        return max_num;

    }
};
int main() {

    int ints[] = {7,6,4,3,1};

    vector<int> input;
    int i = 0;
    for (i=0; i<5; i++)
        input.push_back(ints[i]);

    Solution s;
    std::cout << s.maxProfit(input) << std::endl;
    return 0;
}