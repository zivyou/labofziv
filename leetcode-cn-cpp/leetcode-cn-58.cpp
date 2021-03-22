#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1;
        int count = 0;
        for (;i >= 0; i--){
            if (s[i] != ' ')
                break;
        }

        int on = -1;
        for (;i >=0; i--){
            if (on == -1 && s[i] != ' '){
                on = 1;
            }
            if (on == 1 && s[i] == ' '){
                on = 0;
                return count;
            }

            if (on == 1 && s[i] != ' '){
                count++;
            }
        }

        return count;
    }
};

int main(){
    Solution s;
    cout<<s.lengthOfLastWord(" ")<<endl;
    return 0;
}