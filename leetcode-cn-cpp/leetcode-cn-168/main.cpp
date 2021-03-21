#include <iostream>

using namespace std;
class Solution {
public:
    string int2str(int a){
        string re = "";
        char c = a-1+'A';
        return re+c;
    }

    string convertToTitle(int n) {
        if (n == 0)
            return "";
        if (n <= 26)
            return int2str(n);
        string re = "";
        if (!(n%26)){
            re = convertToTitle(n/26-1) + "Z";
        }else
            re = convertToTitle(n/26)+int2str(n%26);
        return re;
    }
};

int main()
{
    Solution s;
    cout<<s.convertToTitle(676)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
