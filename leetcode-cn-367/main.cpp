#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned int mul = 1;
        for (int i=1; mul=i*i, mul <= num; i++) {
            if (mul == num)
                return true;
        }
        return false;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    Solution s;
    cout<<s.isPerfectSquare(2147483647)<<endl;
    return 0;
}
