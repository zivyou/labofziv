#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int re[n];
        int pos[primes.size()];

        for (int i=0; i<n; i++){
            re[i] = 0;
        }

        for (int i=0; i<primes.size(); i++)
            pos[i] = 0;
        re[0] = 1;
        int index = 0;
        while (index < n-1){
            int current = re[index];
            for (int i=0; i<primes.size(); i++){
                int p = primes[i];
                int j = pos[i];
                while (j < index){
                    if (re[j]*p <= current)
                        j++;
                    else
                        break;
                }
                pos[i] = j;
            }

            int min=INT_MAX;
            for (int i=0; i<primes.size(); i++){
                if (re[pos[i]]*primes[i] < min){
                    min = re[pos[i]]*primes[i];
                }
            }
            re[index+1] = min;
            index++;
        }

        // for (int i=0; i<n; i++)
        //     cout<<re[i]<<" ";
        // cout<<endl;
        return re[n-1];
    }
};


int main(){
    vector<int> primes = {2,7,13,19};
    Solution s;
    cout<<s.nthSuperUglyNumber(12, primes)<<endl;
    return 0;
}