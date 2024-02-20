#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;

class Solution {
private:
    int ** re;
    int f(int n, int a) {
        if (n == 1) return 1;
        if (a <= 0) return n;
        if (n <= 0) return 0;
        // 总长度为n，第一部分划分为a时候的结果
        if (re[n][a] > 0) return re[n][a];
        // printf("n=%d,a=%d\n", n, a);
        // f(n, a) == f(n, n-a);
        // f(n, a) == a*max(f(n-a,1), f(n-a,2), f(n-a,3),...,f(n-a,(n-a)/2+1));
        int max = INT_MIN;
        for (int i=0; i<=(n-a); i++) {
            auto x = f(n-a, i);
            if (x > max) {
                max = x;
            }
        }
        re[n][a] = max*a;
        return a*max;
    }
public:
    int cuttingBamboo(int bamboo_len) {
        re = new int*[bamboo_len+1];
        for (int i=0; i<bamboo_len+1; i++) {
            re[i] = new int[bamboo_len+1];
            fill_n(re[i], bamboo_len+1, 0);
        }

        int max = INT_MIN;
        for (int i=1; i<bamboo_len; i++) {
            auto x = f(bamboo_len, i);
            if (x > max) max = x;
        }

        for (int i=0; i<bamboo_len+1; i++) {
            delete[] re[i];
        }
        delete[] re;
        return max;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    printf("%d\n", s.cuttingBamboo(12));
}
