#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        if (!s.length())
            return true;
        int len = s.length();
        int smap[len+1];
        int tmap[len+1];
        for (int i=0; i<len+1; i++){
            smap[i] = -1;
            tmap[i] = -1;
        }
        for (int i=0; i<len; i++){
            for (int j=i-1; j>=0; j--){
                int sfound = false;
                int tfound = false;
                if (!sfound && s[i] == s[j]){
                    int k = j;
                    while (smap[k] != k)
                        k = smap[k];
                    smap[i] = k;
                    sfound = true;
                }

                if (!tfound && t[i] == t[j]){
                    int k = j;
                    while (tmap[k] != k)
                        k = tmap[k];
                    tmap[i] = k;
                    tfound = true;
                }

                if (sfound && tfound )
                    break;
            }
            if (smap[i] == -1)
                smap[i] = i;
            if (tmap[i] == -1){
                tmap[i] = i;
            }
        }

        for (int i=0; i<len; i++){
            if (smap[i] != tmap[i])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.isIsomorphic("aab", "bbb")<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
