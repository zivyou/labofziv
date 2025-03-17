#include <cstdio>
#include <vector>

using namespace std;

class Solution {
    void append(int x, int n, vector<int>& result) {
        if (x > n) return;
        if (x <= n) result.push_back(x);
        if (x * 10 <= n) append(x*10, n, result);
        append(x+1, n, result);
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        append(1, n, result);
        return result;
    }
};

int main() {
    Solution s;
    auto v = s.lexicalOrder(100);
    for (auto x : v) {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}