#include <iostream>

using namespace std;

class Solution {
public:

    int rawIntegerBreak(int n, int *data){
        if (data[n])
            return data[n];
        if (n <= 4){
            data[n] = n;
            return data[n];
        }

        int max = INT_MIN;
        for (int i = 2; i<n && (n-i) >= 2; i++){
            int t = i * rawIntegerBreak(n-i, data);
            if (t > max){
                max = t;
            }
        }
        data[n] = max;
        return data[n];
    }
    int integerBreak(int n) {
        if (n == 1)
            return 1;
        if (n == 0)
            return 0;
        if (n <= 3)
            return n-1;
        int data[n+1];
        for (int i=0; i<n+1; i++)
            data[i] = 0;
        return rawIntegerBreak(n, data);
    }
};

int main()
{
    Solution s;
    cout<<s.integerBreak()<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
