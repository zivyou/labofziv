//
// Created by youziqi on 2022/7/5.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;
class Solution {
public:
    string decodeString(string s) {
        std::stack<string> st;
        std::string re = "";
        std::string tmpRe = "";
        int count=0;
        for (int i=0; i<s.size(); i++) {
            if (c=='[') {
                re += tmpRe;
                tmpRe.clear();
                continue;
            }
            if (c<='9' && c>='0') {
                count=count*10+c-'0';
                continue;
            }
            if (c==']') {
                for (int j=0;j<count;j++) {
                    re += tmpRe;
                }
                count=0;
                continue;
            }
            tmpRe += c;
        }
    }
};


int main() {

}