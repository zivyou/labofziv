#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int cal(string s, int begin, string t, int *f){
        if (t.length() == 0)
            return 0;
        if (f[begin] != -1)
            return f[begin];
        if (begin + t.length() > s.length())
            return s.length()+1;
        int index = t.find(s[begin]);
        if (index != -1){
            int re = 1+cal(s, begin+1, t.replace(index, 1, ""), f);
            f[begin] = re;
            return re;
        }else{
            int re = 1+cal(s, begin+1, t, f);
            f[begin] = re;
            return re;
        }
    }

    string minWindow(string s, string t) {
        int min = s.length()+1;
        int *f = new int[s.length()];
        for (int i=0; i<s.length(); i++){
            f[i] = -1;
        }
        for (int i=0; i<s.length(); i++){
            f[i] = cal(s, i, t, f);
        }
        string re; int pos=0;
        for (int i=0; i<s.length(); i++){
            cout<<f[i]<<" ";
            if (f[i] > 0 && f[i] < min){
                pos = i;
                min = f[i];
            }
        }
        cout<<endl;
        if (f[pos] > s.length())
            return "";
        else
            return s.substr(pos, f[pos]);
    }
};

int main(){
    Solution s;
    cout<<s.minWindow("a", "a")<<endl;
}