#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> st;
        char c;
        int nCount = 0;
        int cCount = 0;
        int i=0;
        for (i=0; i<preorder.length(); i++){
            c = preorder[i];
            if (c == ',')
                continue;

            if (c == '#')
                cCount++;
            else{
                while (preorder[i] != ',' && i<preorder.length()) i++;
                nCount++;
            }

            if (st.empty()){
                st.push(c);
                continue;
            }
            

            while (st.size() > 1 && c == '#' && st.top() == '#'){
                st.pop();
                st.pop();
            }
            st.push(c);
        }

        if (nCount+1 != cCount){
            //cout<<"nCount = "<<nCount<<", cCount="<<cCount<<endl;
            return false;
        }

        bool ret = st.size() == 1 && st.top() == '#';
        return ret;
    }
};

int main(){
    string str = "1,#,#,1";
    Solution s;
    cout<<s.isValidSerialization(str)<<endl;
}