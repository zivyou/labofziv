#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int isAvalidNum(string s){
        if (stoi(s) > 255)
            return 0;
        if (s.length() != 1){
            if (s[0] == '0')
                return 0;
        }
        return 1;
    }
    void cal(vector<string> & re, string remain, string tmpRe, int cnt){
        if (remain.length() < cnt)
            return;
        if (remain.length() >= 4 && cnt <= 1)
            return;
        if (remain.length()!=0 && cnt == 0)
            return;
        if (cnt == 0 && remain.length()==0){
            re.push_back(tmpRe);
            return;
        }

        
        //cout<<"remian="<<remain<<", tmpRe="<<tmpRe<<", cnt="<<cnt<<endl;

        string remain1; string tmpRe1;
        if (cnt != 4) tmpRe1 = tmpRe + ".";
        remain1 = remain.substr(1);
        tmpRe1 = tmpRe1 + remain.substr(0,1);
        cal(re, remain1, tmpRe1, cnt-1);

        string remain2; string tmpRe2;
        if (cnt !=4)  tmpRe2 = tmpRe + ".";
        if (remain.length() >= 2){
            remain2 = remain.substr(2);
            if (isAvalidNum(remain.substr(0, 2))){
                tmpRe2 = tmpRe2 + remain.substr(0,2);
                cal(re, remain2, tmpRe2, cnt-1);
            }
        }

        string remain3; string tmpRe3;
        if (cnt != 4) tmpRe3 = tmpRe + ".";
        if (remain.length() >= 3){
            remain3 = remain.substr(3);
            if (isAvalidNum(remain.substr(0,3))){
                tmpRe3 = tmpRe3 + remain.substr(0,3);
                cal(re, remain3, tmpRe3, cnt-1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> re;
        cal(re, s, "", 4);
        return re;
    }
};

int  main(){
    Solution s;
    vector<string> re = s.restoreIpAddresses("010010");
    for (int i=0; i<re.size(); i++)
        cout<<re[i]<<" "<<endl;
    return 0;
}