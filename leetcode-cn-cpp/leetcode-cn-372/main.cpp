#include <cstdio>
#include <vector>

using namespace std;

class Solution {
private:
    int phis[1500];
    int gcd(int a, int n) {

    }
    int phi(int n) {

    }

    // a^b mod n
    int mod(int a, int b, int n) {
        if (a == 1) return 1;
        if (b == 1) {
            if (a < n) return a;
            else return a % n;
        }
        if (gcd(a, n) == 1) {
            return mod(a, b % phi(n), n);
        } else {
            if (b < phi(n)) return a**b;
            else return mod(a, b%phi(n)+phi(n), n);
        }
        return mod(a, mod(b, 1, phi(n)), n);
    }

    // a % b <=> a mod b
    int mod(vector<int>& a, int b) {

    }

    bool lessThen(vector<int>& x, int y) {

    }

    // a ^ b mod n
    int mod(int a, vector<int>& b, int n) {
        if (gcd(a, n) == 1) {
            return mod(a, mod(b, phi(n)), n);
        } else {
            if (lessThen(b, phi(n))) return mod(a, b, n);
            else {
                return mod(a, mod(b, phi(n))+phi(n), n);
            }
        }
    }
public:
    int superPow(int a, vector<int>& b) {
        return mod(a, b, 1337);
    }
};