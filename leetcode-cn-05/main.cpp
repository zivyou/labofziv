#include <iostream>
#include <string>

using namespace std;

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