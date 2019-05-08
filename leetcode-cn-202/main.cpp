#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        vector<int> path;
        while (n != 1){
            path.push_back(n);
            int m = 0;
            while (n){
                m = m + (n%10)*(n%10);
                n = n/10;
            }
            //cout<<"m="<<m<<endl;
            if (find(path.begin(), path.end(), m) != path.end())
                return false;
            n = m;
        }

        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.isHappy(21)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
