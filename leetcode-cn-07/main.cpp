#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int re = 0;
        int y = x;
        int range = (int)0x7fffffff;
        if (y < 0)  y = -y;
        if (x == 0) return 0;
        if (y % 10 == 0){
            while (!(y%10))
                y = y/10;
        }
        while (y){
            int t = y%10;
            if (re != (re*10)/10) return 0;
            re = re*10+t;
            if (re > (int)0x7ffffffe || re < 0) return 0;
            y=y/10;
        }

        if (x < 0) return -re;
        else
            return re;
    }
};
int main() {
    Solution s;
    cout<<s.reverse(1534236469)<<endl;
    return 0;
}