#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zigzag-conversion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

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