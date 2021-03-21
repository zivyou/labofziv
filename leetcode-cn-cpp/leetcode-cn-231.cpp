#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {

        int remain;
        while (n){
            if (n == 1)
                return true;
            if (n%2)
                return false;
            n = n/2;
        }

        return false;
    }
};

int main(){

    return 0;
}