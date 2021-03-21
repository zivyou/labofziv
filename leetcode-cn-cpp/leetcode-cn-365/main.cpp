#include <iostream>

using namespace std;

#define abs(x) (x > 0 ? x : -x)
#define min(x, y) (x > y ? y : x)
#define max(x, y) (x > y ? x : y)

class Solution {
public:
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x%y);
    }
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0) return true;
        if (z < 0) return false;
        if (z > x+y) return false;

        int t = gcd(x, y);
        cout<<"t="<<t<<endl;
        return (!(z%t));
    }
};


int main()
{
    Solution s;
    cout<<s.canMeasureWater(13, 11, 1)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
