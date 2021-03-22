#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string int2str(int a){
        stringstream ss;
        string s;
        ss<<a; ss>>s;
        return s;
    }
    string fractionToDecimal(int numerator, int denominator) {
        string re = "";
        int remain = numerator % denominator;
        re = re + int2str(numerator / denominator);
        if (remain == 0)
            return re;

        int count = 100;
        int i=0;
        string decimals = "";
        while (i < count && remain){
            int  consult = remain*10 / denominator;
            decimals = decimals + int2str(consult);
            remain = (remain*10) %  denominator;
            i++;
        }
        if (i < count) {
            return re+"."+decimals;
        }

        
        return "";
    }
};

int main(){
    Solution s;
    cout<<s.fractionToDecimal(1, 3)<<endl;
    return 0;
}