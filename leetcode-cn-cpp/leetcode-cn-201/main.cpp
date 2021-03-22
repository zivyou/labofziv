#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0 )
            return m;

        int minus = n - m;

        bitset<32> bits(m);
        int i=0;
        while(m){
            if (n-m >= 1){
                bits[i++] = 0;
            }
            n = n>>1;
            m = m>>1;
        }
        return bits.to_ulong();
    }
};

int main()
{
    Solution s;
    cout<<s.rangeBitwiseAnd(3,4)<<endl;

    return 0;
}
