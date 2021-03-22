#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bits(n);
        for (int i=0; i<16; i++){
            int rBit = bits[i];
            int lBit = bits[32-i-1];
            bits.set(i, lBit);
            bits.set(32-i-1, rBit);
        }
        return bits.to_ulong();
    }
};

int main()
{
    string str = "00000010100101000001111010011100";
    bitset<32> num(str);

    Solution s;
    cout<<s.reverseBits(num.to_ulong())<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
