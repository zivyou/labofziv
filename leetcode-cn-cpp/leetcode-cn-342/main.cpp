#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0 || num & 1)
            return false;
        if (num == 1)
            return true;

        while (num){
            if (num == 1)
                return true;
            num = num >> 1;
            if (num & 1 && num != 1)
                return false;
            num = num >> 1;
            if (num & 1 && num != 1)
                return false;
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout<<s.isPowerOfFour(5)<<endl;;
    cout << "Hello world!" << endl;
    return 0;
}
