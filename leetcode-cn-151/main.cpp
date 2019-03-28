#include <iostream>

using namespace std;
class Solution {
public:
    void swap(char &a, char &b){
        char c = a;
        a = b;
        b = c;
    }
    void reverseWord(string &s, int begin, int end){
        while (begin < end){
            swap(s[begin], s[end]);
            begin++; end--;
        }
    }
    string rawReverseWords(string s){
        reverseWord(s, 0, s.length()-1);


        int begin = 0; int end = 0;
        while (begin < s.length() && end < s.length()){
            if (end == s.length()-1){
                reverseWord(s, begin, end);
                break;
            }
            if (s[end] == ' '){
                reverseWord(s, begin, end-1);

                begin = end+1;
                end++;
            }else{
                end++;
            }
        }
        return s;
    }
    string reverseWords(string s) {
        for (int i=0; i<s.length(); i++){
            if (s[i] != ' ')
                break;
            else{
                s.erase(s.begin());
                i--;
            }
        }

        for (int i=0; s.length()>0 && i<s.length()-1; i++){
            if (s[i] == ' ' && s[i+1] == ' '){
                s.erase(s.begin() + i);
                i--;
            }
        }

        for (int i=s.length()-1; s.length() > 0 && i>0; i--){
            if (s[i] == ' '){
                s.erase(s.begin()+i);
                i++;
            }else
                break;
        }

        return rawReverseWords(s);
    }
};

int main()
{
    Solution s;
    cout<<s.reverseWords(" my hello world  ")<<"###"<<endl;

    return 0;
}
