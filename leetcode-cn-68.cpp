#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> re;
        vector<string> tempResult;
        for (int i=0; i<words.size(); i++){
            string curStr = words[i];
            int shortestLen = 0;
            int purStrLen = 0;
            for (int j=0; j<tempResult.size(); j++){
                shortestLen = tempResult[j].length()+shortestLen;
                purStrLen = purStrLen + tempResult[j].length();
            }
            shortestLen = tempResult.size() + shortestLen;
                
            if (curStr.length() + shortestLen <= maxWidth){
                tempResult.push_back(curStr);
            }
            else{
                //dump tempResult and reset it
                string str="";
                int blankCount = maxWidth - purStrLen;
                for (int j=0; j<tempResult.size()-1; j++){
                    string s = tempResult[j];
                    str = str+s;

                    if (j< blankCount%(tempResult.size()-1) && blankCount > 0){
                        str = str + string(1+blankCount/(tempResult.size()-1), ' ');
                    }else{
                        str = str + string(blankCount/(tempResult.size()-1), ' ');
                    }
                }
                str = str+tempResult[tempResult.size()-1];
                if (str.length() < maxWidth)
                    str = str+string(maxWidth-str.length(), ' ');
                re.push_back(str);
                tempResult.clear();
                i--;
            }
        }
        if (tempResult.size() != 0){
            string str = "";
            for (int i=0; i<tempResult.size()-1; i++)
                str = str+tempResult[i]+' ';
            str = str+tempResult[tempResult.size()-1];
            if (str.length() < maxWidth)
                str = str+string(maxWidth-str.length(), ' ');
            re.push_back(str);
        }
        return re;
    }
};

int main(){
    string s[] = {"a", "aaaaaaaaaaaaaaa"};
    vector<string> v;
    for (int i=0; i<2; i++){
        v.push_back(s[i]);
    }
    vector<string> re;
    Solution solu;
    re = solu.fullJustify(v, 16);
    for (int i=0; i<re.size(); i++)
        cout<<re[i]<<endl;
    return 0;
}