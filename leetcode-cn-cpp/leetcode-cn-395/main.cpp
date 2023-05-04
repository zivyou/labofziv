#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        cout<<s<<endl;
        if (k <= 1) return s.length();
        if (s.length() <= 0) return 0;
        if (s.length() < k) return 0;
        unsigned int count[26] = {0};
        for (char c : s) {
            unsigned int charNum = c - 'a';
            count[charNum]++;
        }
        char ch = 0;
        for (char c = 'a'; c<='z'; c++) {
            int charNumber = c - 'a';
            unsigned int ccount = count[charNumber];
            if (ccount != 0 && ccount < k) {
                ch = c;
                break;
            }
        }
        if (ch == 0) return s.length();
        int result = 0; int begin = 0;
        for (int i=0;i<s.length();i++) {
            while (s[i] == ch && i<s.length()) {
                i++;
            }
            begin = i;
            while (s[i]!=ch&&i<s.length()) i++;
            result = std::max(longestSubstring(s.substr(begin, i), k), result);
        }
        return result;
    }
};

int main() {
    Solution s;
    cout<<s.longestSubstring("bbaaacbd", 3)<<endl;
    return 0;
}

/*
 * "baaabcb"
3
*/