#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    string cat(int a, string b){
        stringstream oss;
        oss<<a<<b;
        return oss.str();
    }
    string cat2(string b, int a){
        stringstream oss;
        oss<<b<<a;
        return oss.str();
    }
    string sum(string a, string b){
        int carry = 0;
        string result="";
        int i, j;
        for (i=a.length()-1, j=b.length()-1; i>=0 && j>=0; i--, j--){
            int num = a[i] + b[j] - '0'  - '0' + carry;
            if (num >= 10){
                carry = num/10;
                num = num % 10;
            }else
                carry = 0;
            result = cat(num, result);
        }
        if (i < 0){
            for (; j>=0; j--){
                int num = b[j] - '0' + carry;
                if (num > 9){
                    carry = num/10;
                    num = num % 10;
                }else {
                    carry = 0;
                }
                result = cat(num, result);
            }
        } else{
            for (; i>=0; i--){
                int num = a[i] - '0' + carry;
                if (num > 9){
                    carry = num/10;
                    num = num % 10;
                }else {
                    carry = 0;
                }
                result = cat(num, result);
            }
        }
        if (carry > 0)
            result = cat(carry, result);
        return result;
    }
    string oneMultiply(string a, char b){
        string result = "";
        int carry = 0;
        for (int i=a.length()-1; i>=0; i--){
            int num = (a[i]-'0') * (b-'0')+carry;
            if (num >= 10){
                carry = num/10;
                num = num%10;
            }else{
                carry = 0;
            }
            result = cat(num, result);
        }
        if (carry > 0)
            result = cat(carry, result);
        return result;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0"  || num2 == "0")
            return "0";
        if (num1 == "1")
            return num2;
        if (num2 == "1")
            return num1;
        string result = "";
        int cnt=0;
        for (int j=num2.length()-1; j>=0; j--){
            string tmp = oneMultiply(num1, num2[j]);
            for (int i=0; i<cnt; i++)
                tmp = cat2(tmp, 0);
            result = sum(result, tmp);
            cnt++;
        }

        return result;
    }
};

int main(){
    string a="123456789"; string b="987654321";
    Solution s;
    cout<<s.multiply(a, b)<<endl;
}