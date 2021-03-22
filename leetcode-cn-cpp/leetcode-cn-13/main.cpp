#include <iostream>
using namespace std;

class Solution {
public:
    int getNum(char c){
        switch (c){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }

    int romanToInt(string s) {
        int re = 0;
        int i = 0;
        int sign = 0;
        for (i=0; i<s.length(); i++){
            if (i+1 < s.length() && getNum(s[i])<getNum(s[i+1]))
                sign = 1;
            else
                sign = 0;
            if (sign == 1){
                re = re - getNum(s[i]);
            }else
                re = re + getNum(s[i]);
        }
        return re;
    }
};
int main() {
    Solution s;
    cout<<s.romanToInt("IX")<<endl;
    return 0;
}