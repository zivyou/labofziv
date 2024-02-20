
#include <algorithm>
#include <chrono>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
private:
    bool _(int e1, int e2, int e3, int e4, int i, vector<int>& matchsticks) {
        if (i >= matchsticks.size()) {
            if (e1==0 && e2==0 && e3==0 && e4==0) {
                return true;
            } else return false;
        }
        if (e1 < 0) return false;
        if (e2 < 0) return false;
        if (e3 < 0) return false;
        if (e4 < 0) return false;
        auto r1 = _(e1-matchsticks[i], e2, e3, e4, i+1, matchsticks);
        if (r1) return true;
        auto r2 = _(e1, e2-matchsticks[i], e3, e4, i+1, matchsticks);
        if (r2) return true;
        auto r3 = _(e1, e2, e3-matchsticks[i], e4, i+1, matchsticks);
        if (r3) return true;
        auto r4 = _(e1, e2, e3, e4-matchsticks[i], i+1, matchsticks);
        if (r4) return true;
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        long long count = 0;
        for (auto& n : matchsticks) {
            count += n;
        }
        if (count % 4 != 0) return false;
        int edge = count / 4;
        sort(matchsticks.begin(), matchsticks.end(), [&](int x, int y){return x>y;});
        return _(edge, edge, edge, edge, 0, matchsticks);
    }
};

/*
class Solution {
private:
    void __(int edge, vector<int>& matchsticks, vector<int>& result) {
        if (edge == 0) return;
        if (edge < 0) {
            matchsticks.insert(matchsticks.end(), result.begin(), result.end());
            return;
        }
        for (int i=matchsticks.size()-1; i>=0; i--) {
            if (edge > matchsticks[i]) {
                result.push_back(matchsticks[i]);
                __(edge-matchsticks[i], matchsticks, result);
                result.pop_back();
            }
        }
    }
    vector<int> _(int edge, vector<int>& matchsticks) {
        vector<int> result;
        __(edge, matchsticks, result);
        return result;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        long long count = 0;
        for (auto& n : matchsticks) {
            count += n;
        }
        if (count % 4 != 0) return false;
        int edge = count / 4;
        sort(matchsticks.begin(), matchsticks.end());
        auto v1 = _(edge, matchsticks);
        if (v1.empty()) return false;
        auto v2 = _(edge, matchsticks);
        if (v2.empty()) return false;
        auto v3 = _(edge, matchsticks);
        if (v3.empty()) return false;
        auto v4 = _(edge, matchsticks);
        if (v4.empty()) return false;
        return matchsticks.empty();
    }
};
*/
int main(int argc, char* argv[]) {
    auto startTime = chrono::system_clock::now();
    Solution s;
    vector<int> v = {5,5,5,5,4,4,4,4,3,3,3,3};
    printf("%d\n", s.makesquare(v));
    auto endTime = chrono::system_clock::now();
    chrono::duration<double> diff = endTime - startTime;
    printf("执行耗时: %.5f s\n", diff.count());
}
