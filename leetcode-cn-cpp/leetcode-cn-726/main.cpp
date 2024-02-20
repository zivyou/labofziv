#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    bool isNumber(char c) {
        return c >= '0' && c <= '9';
    }
    bool upCase(char c) {
        return c >= 'A' && c <= 'Z';
    }
    bool lowCase(char c) {
        return c >= 'a' && c <= 'z';
    }
    bool isElem(string s) {
        return all_of(s.begin(), s.end(), [&](char c){return isalpha(c);});
    }
    bool isNumber(string s) {
        return all_of(s.begin(), s.end(), [&](char c) { return isNumber(c);});
    }
    int toNumber(string s) {
        return stoi(s);
    }
    map<string, int> mapUnion(const map<string, int>& m1, const map<string, int>& m2) {
        map<string, int> result;
        for (const auto & p : m1) {
            if (m2.find(p.first) == m2.end()) {
                result[p.first] = p.second;
            } else {
                result[p.first] = m1.at(p.first) + m2.at(p.first);
            }
        }
        for (const auto & p : m2) {
            if (m1.find(p.first) == m1.end()) {
                result[p.first] = p.second;
            }
        }
        return result;
    }
    map<string, int> multiply(const map<string, int>& m, int p) {
        map<string, int> result;
        for (const auto & x : m) {
            result[x.first] = x.second * p;
        }
        return result;
    }
    map<string, int> _(vector<string>& strs, int begin, int end) {
        if (begin > end) return {};
        if (end - begin == 1 && isElem(strs[begin]) && isNumber(strs[end])) {
            return {pair<string, int>(strs[begin], toNumber(strs[end]))};
        }

        if (end - begin == 0 && isElem(strs[begin])) {
            return {pair<string, int>(strs[begin], 1)};
        }
        map<string, int> result;

        stack<int> st;
        int i=begin;
        while (i<=end) {
            if (strs[i] == "(") {
                st.push(i);
            }
            if (strs[i] == ")") {
                auto top = st.top();
                st.pop();
                if (st.empty()) {
                    if (i<end && isNumber(strs[i+1])) {
                        auto m1 = _(strs, top+1, i-1);
                        m1 = multiply(m1, toNumber(strs[i+1]));
                        result = mapUnion(result, m1);
                    } else {
                        auto m1 = _(strs, top+1, i-1);
                        result = mapUnion(result, m1);
                    }
                }
            }
            if (st.empty()) {
                if (i+1<=end && isElem(strs[i]) && isNumber(strs[i+1])) {
                    result[strs[i]] += toNumber(strs[i+1]);
                    i++;
                    continue;
                }
                if (isElem(strs[i])) {
                    result[strs[i]] += 1;
                }
            }
            i++;
        }
        return result;
    }
public:
    string countOfAtoms(string formula) {
        /* f(Ka4(ON(SO3)2)2) = f(Ka4) U f((ON(SO3)2)2) = 4f(Ka) U 2f(ON(SO3)2)
         * = 4f(Ka) U 2f(ON) U 2f((SO3)2) = 4f(Ka) U 2f(ON) U 4f(SO3)
         * = 4f(Ka) U 2f(ON) U 4f(S) U 4f(O3)
         *
         */
        vector<string> strs;
        int begin = 0;
        for (auto i=0; i<formula.length(); i++) {
            if (formula[i] == '(') {
                strs.emplace_back("(");
                begin = i+1;
                continue;
            }
            if (isNumber(formula[i])) {
                begin = i; int end = i;
                while (isNumber(formula[end]) && end < formula.length()) end++;
                end--;
                strs.push_back(formula.substr(begin, end-begin+1));
                i = end;
                begin = i+1;
                continue;
            }
            if (formula[i] == ')') {
                strs.emplace_back(")");
                begin = i+1;
                continue;
            }
            if (upCase(formula[i])) {
                begin = i; int end = i+1;
                while (lowCase(formula[end]) && end < formula.length()) end++;
                end--;
                strs.push_back(formula.substr(begin, end-begin+1));
                i = end;
                begin = i+1;
                continue;
            }
        }
        for (const auto& s : strs) {
            printf("%s ", s.c_str());
        }
        printf("\n");
        auto results = _(strs, 0, strs.size()-1);
        stringstream ss;
        for (const auto & p : results) {
            ss<<p.first;
            if (p.second > 1) ss<<p.second;
        }
        printf("%s\n", ss.str().c_str());
        return ss.str();
    }
};
// (HO)2(HO)2(AB)2
// ((C7)26C31)3 => C639
int main(int argc, char* argv[]) {
    Solution s;
    s.countOfAtoms("(H)");
}
