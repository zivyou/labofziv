#include <vector>
#include <cstdio>

using namespace std;

class Solution {
private:
    vector<int> merge(vector<int>& x, vector<int>& y) {
        if (x.empty()) return y;
        if (y.empty()) return x;
#define NEED_LARGE 0
#define NEED_SMALL 1
        bool xNeedLargeOrSmall = x.size() % 2;
        bool yNeedLargeOrSmall = y.size() % 2;
        printf("xNeedLargeOrSmall is %d, yNeedLargeOrSmall is %d\n",xNeedLargeOrSmall, yNeedLargeOrSmall);
        if (xNeedLargeOrSmall == NEED_LARGE && x[x.size()-1] < y[0]) {
            x.insert(x.end(), y.begin(), y.end());
            return x;
        }
        if (yNeedLargeOrSmall == NEED_LARGE && y[y.size()-1] < x[0]) {
            y.insert(y.end(), x.begin(), x.end());
            return y;
        }
        if (xNeedLargeOrSmall == NEED_SMALL && x[x.size()-1] > y[0]) {
            x.insert(x.end(), y.begin(), y.end());
            return x;
        }
        if (yNeedLargeOrSmall == NEED_SMALL && y[y.size()-1] > x[0]) {
            y.insert(y.end(), x.begin(), x.end());
            return y;
        }
        printf("here!\n");
        return {};
    }
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int mid = nums.size() / 2;
        std::vector<int> x; x.assign(nums.begin(), nums.begin()+mid);
        vector<int> y; y.assign(nums.begin()+mid+1, nums.end());

        wiggleSort(x);
        wiggleSort(y);
        const auto& z = merge(x, y);
        nums.assign(z.begin(), z.end());
    }
};

int main() {
    vector v = {1, 5, 1, 1, 6, 4};
    Solution s;
    s.wiggleSort(v);
    for (const auto & n : v) {
        printf("%d ", n);
    }
    printf("\n");
    return 0;
}