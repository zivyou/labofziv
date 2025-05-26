#include <cstdio>
#include <vector>

using namespace std;

class Solution {
private:
    int ***r;
    int **sums;
    int sum(vector<int>&v, int from, int to) {
        if (sums[from][to] > 0) return sums[from][to];
        int re = 0;
        for (int i = from; i <= to; i++) {
            re += v[i];
        }
        sums[from][to] = re;
        return re;
    }
    int _(vector<int> &v, int k, int from, int to) {
        if (r[from][to][k] > 0) return r[from][to][k];
        if (k == 1) {
            re[from][to][k] = std::min
        }
        int re = std::min(_);
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        r = new int **[k+1];
        for (int i = 0; i < k+1; i++) {
            r[i] = new int *[n+1];
            for (int j = 0; j < n+1; j++) {
                r[i][j] = new int[n+1]();
            }
        }

        sums = new int *[n+1];
        for (int i=0; i<n+1; i++) {
            sums[i] = new int[n+1];
        }

        auto re = _(nums, k, 0, n-1);

        for (int i = 0; i < k+1; i++) {
            for (int j = 0; j < n+1; j++) {
                delete r[i][j];
            }
        }

        for (int j = 0; j < n+1; j++) {
            delete sums[j];
        }
        return re;
    }
};

int main(int argc, char *argv[]) {

}
