#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        int aLength = a.length();
        int bLength = b.length();
        int maxLength = aLength < bLength ? bLength : aLength;
        vector<int> carry(maxLength+1, 0);
        string re = "";
        int i=0;
        while (i<aLength && i<bLength){
            int value = (a[i]-'0' + b[i]-'0' + carry[i])%2;
            re = re + std::to_string(value);
            carry[i+1] = (a[i]-'0' + b[i]-'0' + carry[i]) / 2;
            i++;
        }
        if (i < aLength) {
            while ( i < aLength){
                int value = (a[i]-'0'+carry[i])%2;
                re = re + std::to_string(value);
                carry[i+1] = (a[i]-'0' + carry[i]) / 2;
                i++;
            }
        }else {
            while ( i < bLength){
                int value = (b[i]-'0'+carry[i])%2;
                re = re + std::to_string(value);
                carry[i+1] = (b[i]-'0' + carry[i]) / 2;
                i++;
            }
        }
        if (carry[i])
            re = re + std::to_string(carry[i]);
        std::reverse(re.begin(), re.end());
        return re;
    }
};

int main(){
    Solution s;
    cout<<s.addBinary("11110", "100")<<endl;
}