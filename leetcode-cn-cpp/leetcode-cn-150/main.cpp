#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

class Solution {
public:
    int string2int(string s){
        stringstream ss;
        ss<<s;
        int i;
        ss>>i;
        return i;
    }
    string int2string(int a){
        stringstream ss;
        ss<<a;
        string str;
        ss>>str;
        return str;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i=0; i<tokens.size(); i++){
            if (tokens[i] == "+" || tokens[i] == "-"
            || tokens[i] == "*" || tokens[i] == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                if (tokens[i] == "+") {st.push(b+a);}
                if (tokens[i] == "-") {st.push(b-a);}
                if (tokens[i] == "*") {st.push(b*a);}
                if (tokens[i] == "/") {st.push(b/a);}
            }else{
                st.push(string2int(tokens[i]));
            }

        }
        return st.top();
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
