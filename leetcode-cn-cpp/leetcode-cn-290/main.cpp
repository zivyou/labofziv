#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    vector<string> split(string str){
        vector<string> re;
        if (!str.length())
            return re;
        int begin=0; int end=0;
        for (int i=0; i<str.length(); i++){
            if (str[i] == ' '){
                end = i-1;
                re.push_back(str.substr(begin, end-begin+1));
                begin = i+1;
            }
        }
        re.push_back(str.substr(begin));
        return re;
    }

    bool wordPattern(string pattern, string str) {
        if (!pattern.length() || !str.length())
            return false;
        vector<string> strList = split(str);

        if (strList.size() != pattern.length())
            return false;
        int map1[256];
        for (int i=0; i<256; i++)
            map1[i] = -1;
        for (int i=0; i<pattern.length(); i++){
            if (map1[pattern[i]] == -1){
                map1[pattern[i]] = i;
            }else{
                string pre = strList[map1[pattern[i]]];
                string current = strList[i];
                if (pre.compare(current))
                    return false;

                map1[pattern[i]] = i;
            }
        }

        map<string, int> map2;
        for (int i=0; i<strList.size(); i++){

            if (map2.find(strList[i]) == map2.end()){

                map2[strList[i]] = i;
            }else{
                char a = pattern[map2[strList[i]]];
                char b = pattern[i];
                cout<<"a = "<<a<<", b = "<<b<<endl;
                if (a != b)
                    return false;
                map2[strList[i]] = i;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    cout<<s.wordPattern("aba", "dog cat dog")<<endl;
    return 0;
}
