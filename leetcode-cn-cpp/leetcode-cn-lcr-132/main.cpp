#include <algorithm>
#include <cstdint>
#include <cstdio>

using namespace std;

/**
 * \brief todo: 大数计算，直接使用unsinged long long会出现低32位的符号位错误问题
 */
class Solution {
private:
    uint64_t *dp;
    uint64_t _(int len) {
        if (dp[len] > 0) return dp[len];
        uint64_t max = 0;
        for (int i=2; i<=len/2; i++) {
            auto left = i;
            auto right = len - left;
            auto t1 = (_(left) % 1000000007);
            auto t2 = (_(right) % 1000000007);
            auto t = (t1 * t2) % 1000000007;
            if (t > max) max = t;
        }
        dp[len] = max;
        return dp[len];
    }
public:
    int cuttingBamboo(int bamboo_len) {
        if (bamboo_len == 2) return 1;
        if (bamboo_len == 3) return 2;
        dp = new uint64_t[bamboo_len+1];
        fill_n(dp, bamboo_len+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        dp[4] = 4;
        auto re = _(bamboo_len);
        for (int i=0; i<bamboo_len+1; i++) printf("%d:%lld ",i, dp[i]);
        printf("\n");
        delete[] dp;
        return re;
    }
};

// 127 -> 439254203
int main(int argc, char* argv[]) {
    Solution s;
    printf("%d\n", s.cuttingBamboo(127));
}
