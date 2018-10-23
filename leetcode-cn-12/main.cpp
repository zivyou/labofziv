#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string re = "";
        int nM = num / 1000;
        int i = 0;
        for (i=0; i < nM; i++)
            re = re+"M";
        num = num % 1000;
        if (num >= 900) {
            re = re+"CM";
            num = num - 900;
        }else if (num >= 400 && num < 500){
            re = re+"CD";
            num = num - 400;
        }else if (num >= 500){
            re = re+"D";
            num = num - 500;
        }
        {
            i = 0;
            for (i=0; i<num/100; i++){
                re = re+"C";
            }
            num = num % 100;
        };

        if (num >= 90){
            re= re+"XC";
            num = num - 90;
        }else if (num >= 40 && num < 50){
            re = re+"XL";
            num = num - 40;
        }else if (num >= 50){
            re = re + "L";
            num = num - 50;
        }
        {
            i = 0;
            for (i=0; i<num/10; i++){
                re = re+"X";
            }
            num = num % 10;
        }

        if (num == 9){
            re = re+"IX";
            num = num - 9;
        }else if (num == 4){
            re = re+"IV";
            num = num - 4;
        }else if (num >= 5){
            re = re+"V";
            num = num - 5;
        }
        {
            i = 0;
            for (i=0; i<num; i++)
                re = re+"I";
        }
        return re;
    }
};

int main() {
    Solution s;

    cout<<s.intToRoman(1994)<<endl;
    return 0;
}