#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static int charCmp(char a, char b){
        if (a < b)
            return 1;
        else 
            return 0;
    }
    static int strCmp(string a, string b){
        sort(a.begin(), a.end(), Solution::charCmp);
        sort(b.begin(), b.end(), Solution::charCmp);
        if (a.compare(b) < 0)
            return 1;
        else 
            return 0;
    }

    int strCmp2(string a, string b){
        sort(a.begin(), a.end(), Solution::charCmp);
        sort(b.begin(), b.end(), Solution::charCmp);
        return a.compare(b);
    }
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        if (strs.size() <= 0){
            return vector<vector<string> > ();
        }
        vector<vector<string> > result;
        sort(strs.begin(), strs.end(), Solution::strCmp);
        string s=strs[0];
        vector<string> temp;
        for (int i=0; i<strs.size(); i++){
            if (!strCmp2(s, strs[i]))
                temp.push_back(strs[i]);
            else{
                s = strs[i];
                vector<string>t;
                t.swap(temp);
                temp.push_back(s);
                result.push_back(t);
            }
        }
        result.push_back(temp);
        return result;
    }
};

int main(){
    vector<string> v = {"123", "321", "231"};
    Solution s;
    vector<vector<string> > result = s.groupAnagrams(v);
    for (int i=0; i<result.size(); i++){
        for (int j=0; j<result[i].size(); j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}