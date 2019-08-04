#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1)
            return true;
        if (n < 3)
            return false;
        if (n == 3)
            return true;

        int k = n%10;
        if (k != 1 && k != 3 && k!=7 && k!=9)
            return false;

       int t = 3;
       while (t <= n && t<=INT_MAX/3){
            if (t == n)
                return true;
            else
                t = t * 3;
       }
        //cout<<"sum="<<sum<<endl;
        return false;
    }
};

int main(){
    return 0;
}