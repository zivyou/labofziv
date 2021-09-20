#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string a;
    string b;
    vector<vector<int>> m;
    bool search(int startA, int startB){
        int i=startA;
        int j=startB;
        if (m[startA][startB] == 0)
            return false;

        if (m[startA][startB] == 1)
            return true;

//        cout<<"startA ="<<startA<<"startB="<<startB<<endl;
//        system("pause");
        while (i<a.length() && j<b.length()){
            if (a[i]==b[j]){
                i++; j++;
            }else if(b[j]=='?'){
                i++; j++;
            }else if (b[j]=='*'){
                int k=0; int found=0;
                if (j == b.length()-1){
                    m[i][j] = 1;
                    return true;
                }
                for (k=0; i+k<a.length(); k++){
                    if (m[i+k][j+1]==1 || search(i+k, j+1)){
                        m[i+k][j+1] = 1;
                        i = i+k;
                        j++;
                        found=1;
                        break;
                    }else{
                        m[i+k][j+1] = 0;
                    }
                }
                if (!found){
                    m[i][j] = 0;
                    return false;
                }
            }else{
                m[i][j] = 0;
                return false;
            }

        }

        if (i==a.length()){

            for (;j<b.length(); j++)
                if (b[j]!='*'){

                    return false;
                }
            return true;
        }else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> t(s.length()+1, vector<int>(p.length()+1));
        for (int i=0; i<=s.length(); i++)
            for (int j=0; j<=p.length(); j++)
                t[i][j] = -1;

        m = t;
        a = s;
        b = p;
        return search(0, 0);
    }
};

int main()
{
    Solution s;
    cout << s.isMatch("",
"ab*cd?i*de") << endl;
    return 0;
}
