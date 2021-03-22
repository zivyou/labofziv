#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

    void swap(int &a, int &b){
        int c = b;
        b = a;
        a = c;
    }
    vector<int> prevPermOpt1(vector<int>& A) {
        int len = A.size();

        int pos;
        int i;
        for (i=len-1; i>0; i--){
            if (A[i] < A[i-1]){
                pos = i-1;
                break;
            }
        }
        if ( i == 0)
            return A;

        int pos2;
        
        for (i=len-1; i>pos; i--){
            if (A[i] < A[pos]){
                pos2 = i;
                break;
            }
        }

        swap(A[pos], A[pos2]);
        return A;
    }
};

int main(){
    return 0;
}
