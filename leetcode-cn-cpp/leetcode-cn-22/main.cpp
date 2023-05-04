#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<string>& result, const string& current, int& n, int value) {
        if (value < 0) return;
        if (current.length() > n) return;
        if (current.length() == n && value == 0) {
            result.push_back(current);
            return;
        }
        dfs(result, current+'(', n, value + 1);
        dfs(result, current+')', n, value - 1);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        int length = n*2;
        dfs(result, "", length, 0);
        return result;
    }
};

int main() {
    Solution s;
    auto result = s.generateParenthesis(1);
    for (const auto& r : result) {
        cout<<r<<", ";
    }
    cout<<endl;
    return 0;
}