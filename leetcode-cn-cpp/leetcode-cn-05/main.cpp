#include <iostream>
#include <string>

using namespace std;

/**
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 */


/**
 * 从中间的某一个点开始，往两边扩散
 * 分成两种情况；
 * [... X1, X1, ....]和[...X1...]两种扩散方式
 */
class Solution {
public:
    string longestPalindrome(string s) {
        string re = "";
        int i = 0;
        for (i = 0; i<s.length(); i++){
            int k=0;
            while (i-k >= 0 && i+k<s.length()) {
                if (2 * k + 1 > re.length())
                    re = s.substr(i - k, 2 * k + 1);
                if (i - k - 1 >= 0 && i + k + 1 < s.length() && s[i - k - 1] == s[i + k + 1]) {
                    k++;
                }
                else
                    break;
            }

            k=0;
            while (i-k >= 0 && i+k+1<s.length()){
                if (i-k >=0 && i+k+1<s.length() && s[i-k] == s[i+k+1]){
                    if (2*k+2 > re.length())
                        re = s.substr(i-k, 2*k+2);
                    k++;
                }else
                    break;
            }
        }

        return re;
    }
};

int main() {
    string str = "aaaaaaa";
    Solution s;
    cout<<s.longestPalindrome(str)<<endl;
    return 0;
}