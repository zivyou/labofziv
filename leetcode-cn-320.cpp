#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    void dfs(vector<string>&re, string &word, int begin, string tmpRe, int num){
        if (begin == word.length()){
            if (num == 0){
                re.push_back(tmpRe);
            }else{
                re.push_back(tmpRe+std::to_string(num));
            }
            return;
        }
        dfs(re, word, begin+1, tmpRe, num+1);
        string newTmpRe = tmpRe;
        if (num != 0)
            newTmpRe = newTmpRe+(std::to_string(num)+word[begin]);
        else
            newTmpRe = newTmpRe + word[begin];
        dfs(re, word, begin+1, newTmpRe, 0);
    }
    vector<string> generateAbbreviations(string word) {
        vector<string> re;
        string tmpRe;
        dfs(re, word, 0, tmpRe, 0);
        return re;
        
    }
};

int main(){
    Solution s;
    vector<string> re = s.generateAbbreviations("word");
    for (auto str : re){
        cout<<str<<" ";
    }

    cout<<endl;
    return 0;
}