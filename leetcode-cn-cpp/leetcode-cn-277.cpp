#include <iostream>
#include <vector>


using namespace std;

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int count1[n];
        int count2[n];
        for (int i=0; i<n; i++){
            count1[i] = 0;
            count2[i] = 0;
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (i!=j){
                    if (knows(i, j)){
                        count1[j]++;
                        count2[i]++;
                    }
                }
            }
        }

        for (int i=0; i<n; i++){
            if (count1[i] == n-1 && count2[i] == 0)
                return i;
        }

        return -1;
    }
};

int main(){
    return 0;
}
