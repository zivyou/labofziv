#include <cstdio>
#include <string>

using namespace std;

class Solution {
private:
    string commonHead(const string& s1, const string& s2) {
        int i=0;
        for (; i<s1.length() && i<s2.length() && s1[i]==s2[i]; i++);

        return s1.substr(0, i);
    }
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        auto cs1 = commonHead(s1, s2);
        auto cs2 = commonHead(cs1, s3);
        if (cs2.empty()) return -1;
        auto r1 = s1.length()-cs2.length();
        if (s1.length() <= 2 && r1>0) return -1;
        auto r2 = s2.length()-cs2.length();
        if (s2.length() <= 2 && r2>0) return -1;
        auto r3 = s3.length()-cs2.length();
        if (s3.length() <= 2 && r3>0) return -1;
        return r1+r2+r3;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    printf("%d\n", s.findMinimumOperations("a", "aabc", "a"));
}
