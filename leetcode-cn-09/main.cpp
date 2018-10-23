#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        string s="";
        while (x){
            char c = x%10+'0';
            s = s+c;
            x = x/10;
        }
        int i=0; int j=s.length()-1;
        while (i < j){
            if (s[i] == s[j]){
                i++;
                j--;
            }else
                return false;
        }

        return true;
    }
};

int main() {
    Solution s;
    cout<<s.isPalindrome(121)<<endl;
    return 0;
}