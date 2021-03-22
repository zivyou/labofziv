#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void rawNumDistinc(int &re, string curPath, string s, string t){
        if (curPath == t){
            re++;
            return;
        }
        if (curPath.length() + s.length() < t.length())
            return;
        if (s.length() <= 0)
            return;

        cout<<"curPath="<<curPath<<endl;
        if (curPath.length() < t.length()){
            string rawS = s;
            s.erase(0, 1);
            if (t.find(curPath) == 0){
                rawNumDistinc(re, curPath, s, t);
            }
            if (t.find(curPath) == 0){
                rawNumDistinc(re, curPath.append(1, rawS[0]), s, t);
            }
        }
    }

    int numDistinct(string s, string t) {
        int re = 0;
        rawNumDistinc(re, "", s, t);
        return re;
    }
};

int main(){
    Solution s;
    cout<<s.numDistinct("aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe","bddabdcae")<<endl;
    return 0;
}