#include <iostream>

using namespace std;

class Solution {
public:
    int factorial[10];
    string getPermutation(int n, int k) {
        string re;
        factorial[0] = 1;
        for (int i=1; i<=9; i++){
            factorial[i] = i*factorial[i-1];
        }

        int bitWidth = 0;
        for (int i=1; i<=9; i++){
            if (factorial[i] > k){
                bitWidth = i;
                break;
            }
        }

        if (bitWidth == 0)
            return "";
        
        int last = 1;
        // the last $bitWidth number limit to [last+1, n]
        for (last=1; last<=n-bitWidth; begin++)
            re = re+std::to_string(begin);
        int remain = k - begin*();
        re = re + std::to_string();
    }
};

int main(){
    int n = 9;
    int re = 1;
    for (int i=1; i<=n; i++){
        re = re*i;
        cout<<re<<endl;
    }
    return 0;
}