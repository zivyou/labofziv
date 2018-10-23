#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        while (str[i] == ' ')
            str.erase(0, 1);
        int sign = 1;
        i = 0;
        if (str[i] == '-') {
            sign = 0;
            str.erase(0, 1);
        }else if (str[i] == '+'){
            sign = 1;
            str.erase(0, 1);
        }else if (str[i] >= '0' && str[i] <= '9'){
            sign = 1;
        }else
            return 0;
        i=0;
        for (i=0; i<str.length(); i++){
            if (str[i] >= '0' && str[i] <= '9')
                continue;
            else
                break;
        }
        string trueStr = str.substr(0, i);
        int re = 0;
        i = 0;
        for (i=0; i<trueStr.length(); i++){
            if (re != re*10/10){
                if (sign == 0)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
            re = re * 10 + trueStr[i] - '0';
            if (sign == 1 && (unsigned int)re >= (unsigned int)INT_MAX){
                return INT_MAX;
            }else if (sign == 0 && (unsigned int)re >= (unsigned int)INT_MIN)
                return INT_MIN;
        }
        if (sign == 1) return re;
        else return -re;
    }
};
int main() {
    Solution s;
    cout<<s.myAtoi("-2147483647")<<endl;
    return 0;
}