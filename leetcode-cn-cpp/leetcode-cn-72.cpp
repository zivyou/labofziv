#include <cstdio>
#include <limits.h>
#include <string>

using namespace std;

class Solution {
private:
    int** dp;
    void init(int m, int n) {
        dp = new int*[m];
        for (int i=0; i<m; i++) {
            dp[i] = new int[n];
            fill_n(dp[i], n, 0);
        }
    }

    void destroy(int m, int n) {
        for (int i=0; i<m; i++) {
            delete[] dp[i];
        }
        delete[] dp;
    }

    void log(int m, int n) {
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(); int n = word2.size();
        if (m <= 0) return n;
        if (n <= 0) return m;
        init(m+1, n+1);
        for (int i=0; i<=m; i++) {
            dp[i][0] = i;
        }
        for (int i=0; i<=n; i++) {
            dp[0][i] = i;
        }
        dp[0][0] = 0;
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (i==0 && j==0) continue;
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    int r1 = dp[i][j-1]+1;
                    int r2 = dp[i-1][j]+1;
                    int r3 = dp[i-1][j-1]+1;
                    dp[i][j] = min(r1, min(r2, r3));
                }
            }
        }
        int re = dp[word1.size()][word2.size()];
        log(m+1, n+1);
        destroy(m+1, n+1);
        return re;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    printf("%d\n", s.minDistance("pneumonoultramicroscopicsilicovolcanoconiosis", "ultramicroscopically"));
}
