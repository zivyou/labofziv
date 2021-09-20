#include <iostream>
#include <vector>
using namespace std;

/**
 * 编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int amount = strs.size();
        if (amount <= 0)
            return "";
        int i=0;
        string re = "";
        int pos = 0;
        while (1){
            char c;
            if (pos < strs[0].length())
                c = strs[0][pos];
            else
                return re;
            for (i=0; i<amount; i++){
                if (pos < strs[i].length() && strs[i][pos] == c)
                    continue;
                else
                    return re;
            }
            re = re + c;
            pos++;
        }
    }
};
int main() {
    Solution s;
    vector<string> v = {};
    cout<<s.longestCommonPrefix(v)<<endl;
    return 0;
}