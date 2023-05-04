#include <iostream>
#include <string>

using namespace std;

class Solution {
    bool rawMatch(string s, int index, string p, int index2) {
//        if (index >= s.length()) return false;
        for (int i=index2; i<p.length() && index < s.length(); i++) {
            char c = p[i];
            if ('a'<=c && c<='z') {
                if (c == s[index])
                    return rawMatch(s, index+1, p, index2+1);
                else return false;
            } else if (c == '.') {
                return rawMatch(s, index+1, p, index2+1);
            } else if (c == '*') {
                if (p[index2-1] == '.') return true;
                return s[index] == s[index-1] && rawMatch(s, index+1, p, index2);
            } else {
                return false;
            }
        }
        return index >= s.length();
    }
public:
    bool isMatch(string s, string p) {
        return rawMatch(s, 0, p, 0);
    }
};

int main() {
  Solution s;
  cout<<s.isMatch("aab", ".*c")<<endl;
}