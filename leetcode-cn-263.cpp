#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0)
            return false;
        if (!(num % 2)){
            while (!(num % 2)){
                num = num / 2;
            }
            
            if (num == 1)
                return true;
        }

        if (!(num % 3)){
            while (!(num % 3)){
                num = num / 3;
            }
            if (num == 1)
                return true;
        }

        if (!(num % 5)){
            while (!(num % 5)){
                num = num / 5;
            }
            if (num == 1)
                return true;
        }

        if (num != 1)
            return false;
        return true;
    }
};

int main(){
    Solution s;
    cout<<s.isUgly(14)<<endl;
    return 0;
}