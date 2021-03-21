#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int> > f;
    int F(int i, int j){
        if (i==j)
            return 1;
        if (i>j)
            return 0;
        return f[i][j];
    }
    int numDecodings(string s) {
        for (int i=0; i<=s.length(); i++)
            f.push_back(vector<int>(s.length()+1, 0));
        for (int i=0; i<s.length(); i++){
            f[i][i] = 1;
            if (s[i] == '1' )
                f[i][i+1] = 2;
            else if (s[i] == '2' && s[i+1] < '7')
                f[i][i+1] = 2;
            else
                f[i][i+1] = 1;
        }

        for (int i=0; i<s.length(); i++){
            f[0][i] = 0;
            for (int j=0; j<i; j++){
                if (s[j] == '1')
                    f[0][i] = f[0][i] + F(0, j-1) + F(j+2,i);
                else if (s[i] == '2' && s[i+1] < '7')
                    f[0][i] = f[0][i] + F(0, j-1) + F(j+2,i);
                else
                    f[0][i] = f[0][i] + F(0, j) + F(j+1, i);
            }
        }
        return f[0][s.length()-1];
    }
};

int main(){
    Solution s;
    cout<<s.numDecodings("12")<<endl;
    return 0;
}