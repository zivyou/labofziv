#include <cstdio>
#include <string>

using namespace std;

class Solution {
private:
    int _(const string& s1, const string& s2) {
        if (s1 == s2) return -1;
        if (s1.length() > s2.length()) return s1.length();
        if (s2.length() > s1.length()) return s2.length();
        return s1.length();
    }
public:
    int findLUSlength(string a, string b) {
        return _(a, b);
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    printf("%d\n", s.findLUSlength("abbbbb", "cbbbbb"));
}
