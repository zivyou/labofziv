#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> re;
        queue<string> q;
        int i=0;
        string data[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (i=0; i<digits.length(); i++){
            int num=digits[i]-'2';
            int j=0;
            if (q.empty()){
                for (int j=0; j<data[num].length(); j++){
                    string s=(string)""+data[num].at(j);
                    q.push(s);
                }
            }else{
                int loops = q.size();
                for (int k=0; k<loops; k++){
                    string s=q.front();
                    q.pop();
                    for (j=0; j<data[num].length(); j++){
                        string newStr = s+data[num][j];
                        q.push(newStr);
                    }
                }
            }

        }

        while (!q.empty()){
            string s= q.front();
            re.push_back(s);
            q.pop();
        }

        return re;
    }
};
int main() {
    Solution s;
    vector<string> re= s.letterCombinations("9245");
    for (int i=0; i<re.size(); i++)
        cout<<re[i]<<" ";
    cout<<endl;
    return 0;
}