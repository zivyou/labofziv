#include <cstdio>
#include <string>
#include <stack>

using namespace std;

class Solution {

public:
    string removeDuplicateLetters(string s) {
        int counts[27] = {0,};
        std::fill_n(counts, 27, 0);
        for (const auto& c : s) {
            counts[c-'a']++;
        }
        stack<char> st;
        int inserted[27];
        std::fill_n(inserted, 27, 0);
        for (const auto& c : s) {
            if (inserted[c-'a']) {
                counts[c-'a']--;
                continue;
            };
            while (!st.empty() && st.top() > c) {
                if (counts[st.top()-'a'] > 0) {
                    // 如果st.top()这个字符后面还有，就当机立断，抛弃栈里面的这个
                    inserted[st.top()-'a'] = 0;
                    st.pop();
                } else {
                    break;
                }
            }
            counts[c-'a']--;
            if (inserted[c-'a'] == 0) st.push(c);
            inserted[c-'a'] = 1;
        }
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        printf("current result is: %s \n", result.c_str());
        return {result.rbegin(), result.rend()};
    }
};

int main() {
    Solution s;
    const auto &result = s.removeDuplicateLetters("bbcaac");
    printf("result is : %s\n", result.c_str());
}