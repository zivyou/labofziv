#include <iostream>

using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
        int re = 0;
        for (int i=0; i<s.length(); i++){
            re = re*26+(s[i]-'A'+1);
        }

        return re;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
