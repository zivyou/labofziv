#include <cstdio>
#include <vector>
using namespace std;

class Solution {
private:
    void __(vector<int>& result, int n, int start) {
        if (start > n) return;
        int count = 0;
        while (start<=n && count++<9) {
            _(result, n, start);
            start++;
        }
    }

    void _(vector<int>& result, int n, int start) {
        if (start>n) return;;
        int begin = start;
        while (start<=n) {
            result.push_back(start);
            start *= 10;
        }
        for (int i=result.size()-1; result[i]!=begin; i--) {
            __(result, n, result[i]+1);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i=1; i<=9 && result.size()<n; i++) {
            _(result, n, i);
        }

        return result;
    }
};

int main() {
    Solution s;
    int n;
    while (scanf("%d", &n) != EOF) {
        auto result = s.lexicalOrder(n);
        for (auto& x : result) {
            printf("%d ", x);
        }
        printf("\n");
        printf("结果: %d", n==result.size());
    }
    return 0;
}