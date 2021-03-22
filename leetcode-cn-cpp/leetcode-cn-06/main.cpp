#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<char> array[numRows];
        int i = 0;
        int dir = 0;
        int k = 0;
        if (numRows == 1) return s;
        for (i=0; i<s.length(); i++){
            if (i%(numRows-1) == 0){
                if (i/(numRows-1) % 2 == 0)
                    dir = 0;
                else
                    dir = 1;
            }

            if (dir == 0)
                array[k++].push_back(s[i]);
            else
                array[k--].push_back(s[i]);
        }

        k = 0;
        string re="";
        for (k=0;k<numRows;k++){
            int j = 0;
            for (j=0; j<array[k].size(); j++)
                re=re+array[k].at(j);
        }
        return re;
    }
};

int main() {
    Solution s;
    cout<<s.convert("abcd", 2)<<endl;
    return 0;
}