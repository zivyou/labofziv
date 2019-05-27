#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int count = 0;
        for (int i=0; i<customers.size(); i++){
            count = count+customers[i]*(!grumpy[i]);
        }
        int max = 0;

        for (int i=0; i<customers.size()-X+1; i++){
            int tmpRe = count;
            for (int j=i; j<i+X; j++){
                if (grumpy[j]){
                    tmpRe = tmpRe+customers[j];
                }
            }

            if (tmpRe > max)
                max = tmpRe;
        }

        return max;
    }
};


int main(){
    return 0;
}