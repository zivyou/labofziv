#include <algorithm>
#include <cstdio>
#include <string>


using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        if (s.length()<=1) return s;
        sort(s.begin(), s.end(), [](char a, char b){ return a>b; });
        int at = s.size()-1;
        while (at>=0 && s[at]!='1') at--;
        auto t = s[s.size()-1];
        s[s.size()-1] = s[at];
        s[at] = t;
        // printf("%s\n", s.c_str());
        return s;
    }
};


int main(int argc, char* argv[]) {
    Solution s;
    s.maximumOddBinaryNumber("0101");
}
