#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findStr(vector<string>& wordDict, string s){
        if (s.length() == 0)
            return 1;
        for (int i=0; i< wordDict.size(); i++)
            if (wordDict[i] == s)
                return 1;
        return 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        if (findStr(wordDict, s))
            return true;
        int searchResult[s.length()][s.length()] = {0};
        for (int i=1; i<s.length(); i++){
            bool leftFound = false;
            bool rightFound = false;

            if (findStr(wordDict, s.substr(0,i))){
                leftFound = true;
                searchResult[0][i] = 1;
            }else
                searchResult[0][i] = 0;

            if (findStr(wordDict, s.substr(i, s.length()-i))){
                rightFound = true;
                searchResult[i][s.length()-1] = 1;
            }else
                searchResult[i][s.length()-1] = 0;

            if (leftFound && rightFound)
                return true;
        }

        for (int i=0; i<s.length(); i++){
            if (findStr(wordDict, s.substr(i, 1))){
                searchResult[i][i] = 1;
            }else
                searchResult[i][i] == 0;
        }


        for(int length=1; length<=s.length(); length++)
            for (int i=0; i+length<=s.length(); i++){
                searchResult[i][i+length-1] = findStr(wordDict, s.substr(i, length));
                if (!searchResult[i][i+length-1]){
                    for (int j=1; j<=length; j++){
                        if (searchResult[i][i+j-1] && searchResult[i+j][i+length-1]){
                            searchResult[i][i+length-1] = 1;
                            break;
                        }
                    }
                }
            }

        return searchResult[0][s.length()-1];
    }
};

int main()
{
    vector<string> v({"a","aa"});
    Solution s;
    cout<<s.wordBreak("aaaaaaaaaaaaaaaaaa", v)<<endl;
    return 0;
}
