#include <iostream>

using namespace std;

class Solution {
public:
    bool check(char c){
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        if (s.length() <= 1)
            return s;


        int i=0;
        int j=s.length()-1;
        while (i <= j){
            while (i < s.length() && !check(s[i]))
                i++;
            cout<<"i="<<i<<endl;
            while (j >=0 && !check(s[j]))
                j--;
            cout<<"j="<<j<<endl;
            if (i <= j){
                swap(s[i], s[j]);
                i++; j--;
            }else
                break;
        }

        return s;
    }
};

int main()
{
    Solution s;
    cout<<s.reverseVowels("d\"h89 ' 5W4774W5 ' 98h\"d"v)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
