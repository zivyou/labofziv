#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

class Solution {
private:
    bool big_than(const string& s, int target) {
        string t = "";
        while (target > 0) {
            t.push_back(target%2+'0');
            target = target >> 1;
        }
        std::reverse(t.begin(), t.end());
        if (s.length() > t.length()) return true;
        if (s.length() < t.length()) return false;
        for (int i=0; i<s.length(); i++) {
            if (s[i] > t[i]) return true;
        }
        return false;
    }

    bool is_odd(const string& s) {
        return s.back() == '1';
    }

    void rshift(string& s, int num) {
        int n = s.length();
        s.resize(n-num);
    }

    void plus_one(string& s) {
        bool pos = false;
        int i;
        for (i=s.length()-1; i>=0; i--) {
            if (s[i] == '0') {
                s[i] = '1';
                pos = false;
                break;
            }
            if (s[i] == '1') {
                pos = true;
                s[i] = '0';
            }
        }
        if (pos) {
            s.insert(s.begin(), '1');
        }
    }

    int _(string& s) {
        int step = 0;
        while (big_than(s, 1)) {
            // 偶数
            if (!is_odd(s)) {
                // printf("%s is not odd\n", s.c_str());
                rshift(s, 1);
            } else {
                // printf("%s is odd\n", s.c_str());
                plus_one(s);
            }
            step++;
        }
        return step;
    }
public:
    int numSteps(string s) {
        return _(s);
    }
};

// 100100001010010101101000111100100111101111000111111010010001100001000100011001
// 120
int main(int argc, char* argv[]) {
    Solution s;
    printf("=============================> %d\n", s.numSteps("100100001010010101101000111100100111101111000111111010010001100001000100011001"));
}
