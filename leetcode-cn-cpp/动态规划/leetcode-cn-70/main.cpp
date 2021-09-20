#include <iostream>
//https://leetcode-cn.com/problems/climbing-stairs/description/
using namespace std;


class Solution {

public:

    int climbStairs(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        int *re = new int[n+1];
        int i;
        re[0] = re[1] = 1;
        for (i = 2; i<=n; i++)
            re[i] = re[i-1] + re[i-2];
        delete[] re;
        return re[n];

    }

};


int main() {
    int n;
    cin>>n;
    Solution s;

    std::cout << s.climbStairs(n) << std::endl;

    return 0;
}