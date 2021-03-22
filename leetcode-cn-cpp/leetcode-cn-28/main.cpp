#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0)
            return 0;
        if (haystack.length() < needle.length())
            return -1;
        int i, j;
        int re;
        for (i=0; i<haystack.length(); i++) {
            if (haystack[i] != needle[0])
                continue;
            re = i;
            for (j = 0; j < needle.length(); j++){
                if (haystack[re+j] == needle[j])
                    continue;
                else
                    break;
            }

            if (j == needle.length())
                return re;
        }
        return -1;
    }
};
int main() {
    Solution s;
    cout<<s.strStr("aaaaab", "abc")<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}