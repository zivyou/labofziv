#include <algorithm>
#include <climits>
#include <cstdio>
#include <deque>
#include <functional>
#include <vector>

using namespace std;

class MaxDeQueue {
private:
    deque<int> data;
    vector<int> nums;
    int k;
public:
    MaxDeQueue(vector<int>& nums, int k) {
        this->nums = nums;
        this->k = k;
    }
    void push(int index) {
        if (data.empty()) {
            data.push_back(index);
            return;
        }
        while (!data.empty() && nums[data.back()] <= nums[index]) {
            data.pop_back();
        }
        data.push_back(index);
    }
    int getMax() {
        if (data.empty()) {
            return INT_MIN;
        } else {
            return nums[data.front()];
        }
    }
    void pop(int index) {
        if (data.empty()) return;
        if (index - data.front() >= k) {
            data.pop_front();
            while (!data.empty() && nums[data.front()] < nums[index]) {
                data.pop_front();
            }
        }
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MaxDeQueue queue(nums, k);
        for (int i = 0; i < k; ++i) {
            queue.push(i);
        }
        vector<int> res;
        res.push_back(queue.getMax());
        for (int i = k; i < nums.size(); ++i) {
            queue.push(i);
            queue.pop(i);
            res.push_back(queue.getMax());
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {1,3,1,2,0,5};
    auto result = s.maxSlidingWindow(nums, 3);
    for (const auto & x : result) {
        printf("%d  ",x);
    }
    printf("\n");
}
