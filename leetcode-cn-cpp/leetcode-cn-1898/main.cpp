#include <cstdio>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    bool subSeq(const string& s, const string& p, unordered_set<int>& deleted) {
        int x = 0; int y = 0;
        while (x < s.length() && y < p.length() && s.length()-x>=p.length()-y) {
            if (deleted.find(x) != deleted.end()) {
                x++;
                continue;
            }
            if (s[x] == p[y]) {
                x++; y++;
            } else {
                x++;
            }
        }
        if (y >= p.length()) return true;
        else return false;
    }

    int _(const string& s, const string& p, vector<int>& removable, unordered_set<int>& deleted) {
        int k = 0;
        for (k=0; k<=removable.size(); k++) {
            if (k > 0) deleted.insert(removable[k-1]);
            if (!subSeq(s, p, deleted)) return std::max(k-1, 0);
        }
        return removable.size();
    }
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        if (removable.empty()) return 0;
        unordered_set<int> deleted;
        return _(s, p, removable, deleted);
    }
};


int main(int argc, char* argv[]) {
    Solution s;
    auto v = vector<int>{3,2,1,4,5,6};
    printf("%d\n", s.maximumRemovals("abcbddddd", "abcd", v));
}
