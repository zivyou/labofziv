#include <iostream>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n > 10)
            return 0;
        int re = 0;
        
        while (n >= 1){
            int tmp = 9;
            for (int i=1; i<n; i++){
                tmp = tmp * (10-i);
            }
            re += tmp;
            n--;
        }

        return re+1;
    }
};

int main(){
    Solution s;
    cout<<s.countNumbersWithUniqueDigits(1)<<endl;
}