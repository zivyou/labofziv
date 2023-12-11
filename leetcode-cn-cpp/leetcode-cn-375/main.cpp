#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    int **re;
private:
    int minPath(int left, int right) {
        if (left >= right) return 0;
        if (re[left][right] > 0) return re[left][right];
        int min = INT_MAX;
        for (int i=left; i<right; i++) {
            auto x = i + std::max(minPath(left, i-1), minPath(i+1, right));
            if (x < min) min = x;
        }
        re[left][right] = min;
        return min;
    }
public:
    int getMoneyAmount(int n) {
        re = new int*[n+1];
        for (int i=0; i<n+1; i++) {
            re[i] = new int[n+1];
            std::fill_n(re[i], n+1, -1);
        }
        int t = minPath(1, n);
        for (int i=0; i<n+1; i++) {
            delete[] re[i];
        }
        return t;
    }
};
int main() {
    Solution s; int n;
    while (scanf("%d", &n) != EOF) {
        printf("output is: %d", s.getMoneyAmount(n));
    }
    return 0;
}

/**
* 16 -> 34
*/