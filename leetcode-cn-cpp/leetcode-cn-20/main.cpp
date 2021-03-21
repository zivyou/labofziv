#include <iostream>
#include <string>
#include <stack>

using namespace std;
class Solution {
public:
    int leftOrRight(char c){
        if (c == '(' || c=='[' || c=='{')
            return -1;
        else
            return 1;
    }

    bool matched(char c1, char c2){
        if ((c1=='(' && c2==')') || (c1=='['&&c2==']') ||
                (c1=='{' && c2=='}'))
            return true;
        else
            return false;
    }
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        for (i=0; i<s.length(); i++){
            if (st.empty()){
                if (leftOrRight(s[i])<0)
                    st.push(s[i]);
                else
                    return false;
                continue;
            }

            if (leftOrRight(s[i]) < 0)
                st.push(s[i]);
            else{
                char c=st.top();
                if (matched(c, s[i])){
                    st.pop();
                }else
                    return false;
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};
int main() {
    Solution s;
    cout<<s.isValid("(({}))[]")<<endl;

    return 0;
}