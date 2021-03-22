#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    bool isPalindrome(string s, int a, int b){

        while (a < b){
            if (s[a] != s[b])
                return false;
            a++; b--;
        }
        return true;
    }

    void rawPartition(vector<vector<string>> &re, vector<string> tmpRe, string &s, int a, int b){
      if (a >= b){
          re.push_back(tmpRe);
          return;
      }
      for (int i=a; i<b; i++){
          if (isPalindrome(s, a, i)){
              tmpRe.push_back(s.substr(a, i-a+1));
              rawPartition(re, tmpRe, s, i+1, b);
              tmpRe.pop_back();
          }
      }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> re;
        vector<string> tmpRe;
        rawPartition(re, tmpRe, s, 0, s.size());

        return re;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> re = s.partition("abbaabba");
    for (int i=0; i<re.size(); i++){
        for (int j=0; j<re[i].size(); j++)
            cout<<re[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
