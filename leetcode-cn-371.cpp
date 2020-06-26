#include <iostream>
#include <bitset>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int carry[32+1] = {0};
        bitset<32> re;

        int i=0;
        for (i=0; i<32; i++) {
            int tmp = 1 << i;
            bool ai = a & tmp;
            bool bi = b & tmp;
            if (ai == 1 && bi == 0 && carry[i] == 0) {
                re[i] = 1;
                continue;
            }
            if (ai == 0 && bi == 1 && carry[i] == 0) {
                re[i] = 1;
                continue;
            }

            if (ai == 0 && bi == 0 && carry[i] == 1) {
                re[i] = 1;
                continue;
            }

            if ( (ai == 1 && bi == 1 && carry[i] == 0) || (
                ai == 1 && bi == 0 && carry[i] == 1
            ) || (ai == 0 && bi == 1 && carry[i] == 1)) {
                re[i] = 0;
                carry[i+1] = 1;

                continue;
            }

            if (ai == 1 && bi == 1 && carry[i] == 1) {
                re[i] = 1;
                carry[i+1] = 1;
                continue;
            }
        }

        return re.to_ulong();
    }
};



int main() {
    Solution s;
    cout<<s.getSum(-1, INT_MAX)<<endl;
    return 0;
}