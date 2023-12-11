#include <cstdio>
#include <string>
#include <vector>

using namespace std;
class Solution {
private:
    string _(string& s, int k) {
        vector<char> v;
        vector<int> vcounts;
        for (auto & c : s) {
            if (!v.empty() && v.back() == c) {
                auto& count = vcounts.back();
                if (count+1 >= k) {
                    while (!v.empty() && v.back() == c) {
                        v.pop_back();
                        count--;
                    }
                    vcounts.pop_back();
                } else {
                    v.push_back(c);
                    count++;
                }
            } else {
                v.push_back(c);
                vcounts.push_back(1);
            }
        }
        return {v.begin(), v.end()};
    }
public:
    string removeDuplicates(string s, int k) {
        return _(s, k);
    }
};

int main() {
    Solution s;
    printf("%s\n", s.removeDuplicates("yfttttfbbbbnnnnffbgffffgbbbbgssssgthyyyy", 4).c_str());
}