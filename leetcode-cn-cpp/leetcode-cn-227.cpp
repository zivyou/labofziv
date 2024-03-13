#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        bool isNumber = std::all_of(s.begin(), s.end(), [](char c){ return isdigit(c);});
    }
};

int main(int argc, char* argv[]) {
    return 0;
}
