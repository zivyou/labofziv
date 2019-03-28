#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> mySplit(string s, char c){
        int begin = 0;
        int end = 0;
        vector<string> re;
        for (int i=0; i<s.length(); i++){
            if (c == s[i]){
                end = i-1;
                re.push_back(s.substr(begin, end-begin+1));
                begin = i+1;
            }
        }

        if (begin < s.length())
            re.push_back(s.substr(begin, s.length()-begin));
        return re;
    }
    int compareVersion(string version1, string version2) {
        vector<string> v1 = mySplit(version1, '.');
        vector<string> v2 = mySplit(version2, '.');
        /*
        for (int k=0; k<v1.size(); k++)
            cout<<v1[k]<<" ";
        cout<<endl;
        for (int k=0; k<v2.size(); k++)
            cout<<v2[k]<<" ";
        cout<<endl;
        */

        int i;
        for (i=0; i<v1.size()&&i<v2.size(); i++){
            int num1; int num2;
            stringstream ss;
            ss<<v1[i]; ss>>num1;
            ss.clear();
            ss<<v2[i]; ss>>num2;
            if (num1 > num2) return 1;
            if (num1 < num2) return -1;
        }
        if (i == v1.size() && i== v2.size()){
            return 0;
        }
        else if (i < v2.size()){
            int num;

            int j = i;

            while (j < v2.size()){
                                stringstream ss;
                ss<<v2[j];ss>>num;
                if (num != 0)
                    return -1;
                j++;
            }
            return 0;
        }else if (i < v1.size()){
            int num;

            int j = i;

            while (j < v1.size()){
                stringstream ss;
                ss<<v1[j];ss>>num;
                if (num != 0)
                    return 1;
                j++;
            }
            return 0;
        }else{
            return 0;
        }
    }
};

int main()
{
    Solution s;
    cout<<s.compareVersion("1.01", "1.0001")<<endl;

    return 0;
}
