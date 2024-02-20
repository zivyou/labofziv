#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() < 3) return false;
        for (int i=0; i+2 < arr.size(); i++) {
            auto x1 = arr[i]; auto x2 = arr[i+1]; auto x3 = arr[i+2];
            if (x1%2 && x2%2 && x3%2) return true;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {

}
