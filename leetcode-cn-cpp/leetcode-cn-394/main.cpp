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
        std::stack<int> counts;
        std::string context;
        int count = 0;
        for (char c : s) {
            if (c=='[') {
                counts.push(count);
                count = 0;
                st.push(context);
                context.clear();
                continue;
            }
            if (c<='9' && c>='0') {
                count=count*10+c-'0';
                continue;
            }
            if (c==']') {
                count = counts.top();
                counts.pop();
                string tmpRe;
                for (int j=0;j<count;j++){
                    tmpRe += context;
                }
                count = 0;
                context = st.top()+tmpRe;
                st.pop();
                continue;
            }
            context += c;
        }
        string re = context;
        string t;
        while (!st.empty()) {
            t=st.top();
            st.pop();
            re = t+re;
        }
        return re;
    }
};


int main() {
    Solution s;
    cout<<s.decodeString("2[a3[b]]")<<endl;
    cout<<s.decodeString("3[a2[c]]")<<endl;
    cout<<s.decodeString("abc")<<endl;
    cout<<s.decodeString("2[abc]")<<endl;
    cout<<s.decodeString("2[a]3[b]")<<endl;
    cout<<s.decodeString("2[3[b]a]")<<endl;
    cout<<s.decodeString("2[a]3[b]c")<<endl;
    cout<<s.decodeString("abc3[d]e")<<endl;
    cout<<"=============="<<endl;
    cout<<s.decodeString("3[a]2[bc]")<<endl;
    cout<<s.decodeString("3[a2[c]]")<<endl;
    cout<<s.decodeString("2[abc]3[cd]ef")<<endl;
    cout<<s.decodeString("abc3[cd]xyz")<<endl;
}