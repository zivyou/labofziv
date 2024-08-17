#include <climits>
#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        int i=0; int j=0; int length = fruits.size();
        if (length<=2) return length;
        int max = 1; unordered_set<int> choosen = {fruits[0]};
        while (i<=j && i<length && j<length) {
            printf("i=%d, j=%d \n", i, j);
            for (int ii=i; ii<=j; ii++) printf("%d ", fruits[ii]);
            printf("\n");
            j++;
            if (j>=length) {
                if (length-i>max) max = length-i;
                break;
            }
            if (choosen.size()<2) {
                choosen.insert(fruits[j]);
                continue;
            }
            if (choosen.find(fruits[j])!=choosen.end()) {
                continue;
            }
            if (j-i>max) max = j-i;
            int k=j-1;
            while (k>0 && fruits[k]==fruits[k-1]) k--;
            choosen.erase(fruits[k-1]); j--;
            i=k;
        }
        return max;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> v = {0,1,1,4,3};
    printf("%d\n", s.totalFruit(v));
}
