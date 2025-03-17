//
// Created by ziv on 24-12-2.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

/*
 A={h1, k1}, B={h2, k2};
 (1) h1>=h2 && k1>=k2 => A > B; [6,0] [7, 1],[3,0] 不成立
 (2) h1>=h2 && k1<=k2 => A < B; 成立
 (3) h1 <= h2 && k1>=k2 => A > B; 成立
 (4) h1 <= h2 && k1<=k2 => A < B; 不成立
 */

// 可以试一下选择排序

class Solution {

private:
    void _(vector<vector<int>>& data, vector<vector<int>>::iterator l, vector<vector<int>>::iterator r) {
        if (l < data.begin() || r > data.end()) return;
        if (l >= r) return;
        sort(l, r, [](const vector<int>& x, const vector<int>& y) {
            if (x[0] < y[0]) return true;
            if (x[0] == y[0]) return x[1] < y[1];
            return false;
        });
        auto start = l;
        auto part = (*start)[1];
        auto mid = data.begin()+part;
        printf("part = %d\n", part);
        iter_swap(start, mid);
        if (start < mid) _(data, start, mid-1);
        if (mid < r) _(data, mid+1, r);
    }
public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
        _(people, people.begin(), people.end());
        return people;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    std::vector<std::vector<int>> data = {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
    // vector<vector<int>> data = {{1, 1}, {2, 0}};
    vector<vector<int>> result = s.reconstructQueue(data);
    for(int i=0;i<result.size();i++) {
        for(int j=0;j<result[i].size();j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
