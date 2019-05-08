#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:

    int countPrimes(int n) {
        int re = n-2;
        int map[n/32+1] = {0};
        int i=2;
        while (i<=(n/2+1)){
            int j = i;
            int limit = (n%i==0) ? (n/i) : (n/i)+1;
            while (j < limit){
                bitset<32> bits(map[(i*j)/32]);
                bool exist = false;
                if (bits[(i*j)%32] == 1)
                    exist = true;

                if (!exist){
                    re--;
                    bits[(i*j)%32] = 1;
                    map[(i*j)/32] = bits.to_ulong();

                }
                j++;
            }
            i++;
        }
        return re > 0 ? re : 0;
    }
};

int main()
{
    Solution s;
    cout<<s.countPrimes(1000)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
