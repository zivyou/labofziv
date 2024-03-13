#include <algorithm>
#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    int _(vector<int>& v1, vector<int>& v2) {
        int count = 0;
        for (int i=0; i<v1.size(); i++) {
            if (v1[i]!=v2[i]) count++;
        }
        return count;
    }
    vector<vector<int>> vectorUnion(vector<vector<int>>& vectors) {
        if (vectors.empty()) return {};
        auto result = vector<vector<int>>{ vectors[0]};
        for (int i=1; i<vectors.size(); i++) {
            vector<int> intersection;
        }
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        if (allowedSwaps.empty()) {
            return _(source, target);
        }
        if (allowedSwaps.size() == 1) {
            unordered_set<int> swap = {allowedSwaps[0].begin(), allowedSwaps[0].end()};
            vector<int> v1; vector<int> v2;
            vector<int> v3; vector<int> v4;
            for (int i=0; i<source.size(); i++) {
                if (swap.find(i)!=swap.end()) {
                    v1.push_back(source[i]);
                    v2.push_back(target[i]);
                } else {
                    v3.push_back(source[i]);
                    v4.push_back(target[i]);
                }
            }
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            return _(v1, v2) + _(v3, v4);
        }
        auto unionedVectors = vectorUnion(allowedSwaps);
        int result = 0;
        for (const auto& vs : unionedVectors) {
            vector<vector<int>> t = {vs};
            result += minimumHammingDistance(source, target, t);
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
}
