#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        for (int i=0; i<s1.length(); i++){
            cout<<" ============="<<s3<<endl;
            char c = s1[i];
            int j;
            for (j=0; j<s3.length(); j++){
                if (s3[j] == c)
                    break;
            }
            if (j == s3.length())
                return false;
            else{
                string::iterator iter = s3.begin();
                s3 = s3.erase(j, 1);
            }
        }
        
        if (s2.length() != s3.length())
            return false;
        if (s2.compare(s3))
            return false;

        return true;
    }
};

int main(){
    Solution s;
    cout<<s.isInterleave("aabcc", "dbbca", "aadbbcbcac")<<endl;;
}