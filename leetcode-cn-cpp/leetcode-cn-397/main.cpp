#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
private:
    std::unordered_map<unsigned int, int> result;
    int F(unsigned int n) {
        if (result.find(n) != result.end()) return result[n];
        if (n % 2 == 0) {
            result[n] = 1+F(n/2);
            return result[n];
        } else {
            unsigned int i = n+1; unsigned int e1 = 0;
            unsigned int j = n-1; unsigned int e2 = 0;
            while (i % 2 == 0) {
                i = i/2;
                e1++;
            }
            while (j % 2 == 0) {
                j = j/2;
                e2++;
            }
            result[n] = std::min(F(i)+e1, F(j)+e2)+1;
            return result[n];
        }
    }
public:
    int integerReplacement(int n) {
        result[1] = 0;
        result[2] = 1;
        result[3] = 2;
        return F(n);
    }
};
int main() {
    Solution s;
    std::cout<<s.integerReplacement(51)<<std::endl;
    return 0;
}

/*
 * 100000000 -> 31
 */