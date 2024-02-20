#include <algorithm>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        if (list1.empty() || list2.empty()) return {};
        unordered_map<string, int> map1;
        unordered_map<string, int> map2;
        for (auto i=0; i<list1.size(); i++) {
            map1[list1[i]] = i;
        }
        for (auto i=0; i<list2.size(); i++) {
            map2[list2[i]] = i;
        }

        vector<pair<string, int>> results;
        if (list1.size() > list2.size()) {
            for (const auto& s : list2) {
                if (map1.find(s) == map1.end()) {
                    continue;
                }
                int sum = map1[s] + map2[s];
                results.emplace_back(s, sum);
            }
        } else {
            for (const auto& s : list1) {
                if (map2.find(s) == map2.end()) {
                    continue;
                }
                results.emplace_back(s, map1[s]+map2[s]);
            }
        }
        sort(results.begin(), results.end(), [](pair<string, int>&p1, pair<string, int>&p2) {
            return p1.second < p2.second;
        });
        // for (const auto & x : results) {
        //     printf("%s:%d ", x.first.c_str(), x.second);
        // }
        // printf("\n");
        auto max = results.begin()->second;
        vector<string> result2;
        for (const auto& p : results) {
            if (p.second == max) {
                result2.push_back(p.first);
            }
            if (p.second < max) break;
        }
        return result2;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<string> v1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> v2 = {"KFC","Shogun","Burger King"};
    auto x = s.findRestaurant(v1, v2);
    for (auto s : x) {
        printf("%s ", s.c_str());
    }
    printf("\n");
}
