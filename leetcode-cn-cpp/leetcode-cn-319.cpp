#include <iostream>
#include <set>
#include <math.h>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return n;
        int re = 0;
        for (int i=1; i<=n; i++){
            int r1 = (int)sqrt(i);
            if (r1*r1 == i){
                //cout<<"i="<<i<<", r1="<<r1<<endl;
                re++;
            }
        }
        return re;
    }
};


/*
class Solution {
public:
    void cal(int i, int *count){

        int amount = 1;
        for (int j=2; j<=i; j++){
            if (i%j == 0){
                int t = i/j;
                if (t < j)
                    break;
                else if (t == j)
                    amount++;
                else
                    amount += 2;
            }
        }
        count[i] = amount;
    }
    int bulbSwitch(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return n;

        int count[n+1];
        for (int i=0; i<n+1; i++)
            count[i] = 0;
        count[1] = 1;
        for (int i=2; i<n+1; i++){
            cal(i, count);
        }

        int re=1;
        for (int i=2; i<n+1; i++){
            if (count[i]%2 == 0)
                re++;
        }

        return re;
    }
};

*/

int main(){

    Solution s;
    cout<<s.bulbSwitch(9999)<<endl;
    return 0;
}