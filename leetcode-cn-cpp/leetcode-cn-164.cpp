
#include <climits>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
    int pows[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    int pow(int index) {
        return pows[index];
    }
    vector<int> bucketSort(vector<int>& nums) {
        int max = INT_MIN;
        for (const auto& n : nums) {
            if (n > max) max = n;
        }
        vector<int> data = {nums.begin(), nums.end()};
        vector<queue<int>> buckets;
        for (int i=0; i<10; i++) buckets.emplace_back();
        for (int x=0; pow(x)<=max; x++) {
            for (auto n : data) {
                buckets[(n/pow(x))%10].push(n);
            }

            data.clear();
            for (int i=0; i<10; i++) {
                while (!buckets[i].empty()) {
                    data.push_back(buckets[i].front());
                    buckets[i].pop();
                }
            }
        }
        return data;
    }
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        auto result = bucketSort(nums);
        int max = INT_MIN;
        for (int i=0; i+1<result.size(); i++) {
            if (result[i+1]-result[i] > max) {
                max = result[i+1]-result[i];
            }
        }
        return max;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> data = {20, 18, 16, 14, 12, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    s.maximumGap(data);
}
