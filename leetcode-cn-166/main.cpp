#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string int2str(long long a){
        stringstream ss;
        string s;
        ss<<a; ss>>s;
        return s;
    }
    string fractionToDecimal(int numerator, int denominator) {
        long long numA = numerator;
        long long numB = denominator;
        bool sign = false;
        if ((numA < 0 && numB >0)){
            numA = -numA;
            sign = true;
        }else if (numA > 0 && numB < 0){
            numB = -numB;
            sign = true;
        }else{}

        string re = "";
        if (sign){
            re = "-"+re;
        }

        long long remain = numA % numB;
        re = re + int2str(numA / numB);
        if (remain == 0)
            return re;

        int count = 2000;
        int i=0;
        string decimals = "";
        while (i < count && remain){
            int  consult = remain*10 / numB;
            decimals = decimals + int2str(consult);
            remain = (remain*10) %  numB;
            i++;
        }
        if (i < count) {
            return re+"."+decimals;
        }

        int j,k,l;
        for (j=0; j<decimals.length()/2; j++){ //start point
            for (k=1; k<decimals.length()/2;k++){ // per length
                string s = decimals.substr(j, k);
                //cout<<"s=============="<<s<<endl;
                bool myBreak = false;
                for (l=j; l<decimals.length(); l=l+k){
                    if (s == decimals.substr(l, k)){

                    }else{
                        myBreak = true;
                        break;
                    }
                }


                if (!myBreak)
                    return re+"."+decimals.substr(0,j)+"("+s+")";


                if (myBreak && (s.find(decimals.substr(l, decimals.length()-l))  != std::string::npos))
                    return re+"."+decimals.substr(0,j)+"("+s+")";
            }

        }

        return "";
    }
};

int main(){
    Solution s;
    cout<<s.fractionToDecimal(2147483647,370000)<<endl;
    return 0;
}
