#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isLikely(char b, char c){
        if (b == c)
            return true;
        if (b >= 'a' && b <= 'z'){
            if (b-c == 32)
                return true;
        }

        if (b >= 'A' && b <= 'Z'){
            if (c-b == 32)
                return true;
        }

        return false;
    }

    bool isTarget(char c){
        if (c >= '0' && c <= '9')
            return true;
        if (c >= 'a' && c <= 'z')
            return true;
        if (c >= 'A' && c <= 'Z')
            return true;
        return false;

    }
    bool isPalindrome(string s) {
        if (s.length() <= 1)
            return true;
        int len = s.length();
        int i=0; int j=len-1;
        while (i <= j){

            //printf("i=%d, j=%d\n", i,j);
            if (i >= j)
                return true;
            if (!isTarget(s[i])){
                i++;
                continue;
            }

            if (!isTarget(s[j])){
                j--;
                continue;
            }
            if (isLikely(s[i], s[j])){
                i++;j--;
            }
            else
                return false;
        }

        return true;
    }
};

int main()
{
    Solution s;
    //cout<<s.isLikely('a', 'a')<<endl;
    cout << s.isPalindrome("aa") << endl;
    return 0;
}
