#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        string origin = num;
        reverse(origin.begin(), origin.end());
        int len = num.length();
        for (int i=0; i<len; i++){
            if ( (len % 2) && i == (len/2))
                continue;

            if (num[i] == '6'){
                num[i] = '9';
            }else if (num[i] == '9'){
                num[i] = '6';
            }else if (num[i] == '0' || num[i] == '1' || num[i] == '8'){
                continue;
            }else
            {
                return false;
            }
            
        }

        return !origin.compare(num);
    }
};

int main(){

    return 0;
}