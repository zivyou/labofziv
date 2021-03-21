#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:

    bool isPalindromes(string s){
        int i=0; int j=s.length()-1;
        while (i<=j){
            if (s[i] != s[j])
                return false;

            i++;j--;
        }

        return true;
    }

    void dfs(map<string, bool> & re, string &s, int end, string& tmpRe){
        if (end < 0){
            if (tmpRe.length() == s.length() && isPalindromes(tmpRe)){
                re[tmpRe] = true;;
            }
            return;
        }

        char c = s[end];
        for (int i=0; i<=tmpRe.length(); i++){
            string newTmpRe = tmpRe;
            newTmpRe.insert(newTmpRe.begin()+i, c);
            dfs(re, s, end-1, newTmpRe);
        }
    }
    vector<string> generatePalindromes(string s) {
        map<string, bool> re;
        string tmp="";
        dfs(re, s, s.length()-1, tmp);
        vector<string> ret;
        for (auto pair: re){
            if (pair.second){
                ret.push_back(pair.first);
            }
        }
        return ret;
    }
};


/*
class Solution {
public:

    void dfs(vector<string>& re, map<char, int>& count, int len, map<char, int>::iterator& iter, string str){
        if (str.length() == len){
            re.push_back(str);
            return;
        }

        for (int i=0; i<str.length()/2; i++){

        }
    }
    vector<string> generatePalindromes(string s) {
        map<char, int> count;

        for (auto c:s){
            count[c] = 0;
        }

        for (auto c:s){
            count[c]++;
        }

        char single; int amount=0;
        for (auto pair : count){
            if (pair.second == 1){
                single = pair.first;
                amount++;
            }
        }

        if (amount > 1){
            return vector<string>();
        }

        vector<string> re;
        if (amount == 1){
            string str = "";
            str = str + single;
            count[single] = 0;
            dfs(re, count, s.length(), count.begin(), str);
        }else{
            string str;
            dfs(re, count, s.length(), count.begin(), str);
        }

        return re;
    }
};
*/

int main(){
    vector<string> re;
    Solution s;
    re = s.generatePalindromes("aabbhijkkjih");

    for (auto str : re){
        cout<<str<<endl;
    }
    return 0;
}