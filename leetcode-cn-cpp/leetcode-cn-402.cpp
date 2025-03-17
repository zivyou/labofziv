//
// Created by ziv on 24-12-1.
//

#include <algorithm>
#include <cstdio>
#include <string>
#include <stack>
#include <vector>

using namespace std;
/*
单调栈
*/

class Solution {
private:
    void build(stack<char> &left, string &num) {
        if (num.empty()) {
            return;
        }
        while (left.empty() || left.top() <= num.front()) {
            left.push(num.front());
            num.erase(num.begin());
        }
    }

public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) {
            return "0";
        }
        stack<char> left;
        int i = 0;
        while (i++ < k) {
            if (left.empty()) {
                build(left, num);
            }
            left.pop();
            build(left, num);
        }
        vector<char> st;
        while (!left.empty()) {
            st.push_back(left.top());
            left.pop();
        }
        string result = string(st.rbegin(), st.rend());
        result.erase(0, min(result.find_first_not_of('0'), result.size()));
        auto ret = result + num;
        return ret.size() == 0 ? "0" : ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    printf("%s\n", s.removeKdigits("112", 1).c_str());
}
