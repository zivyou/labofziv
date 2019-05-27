#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> re;
        for (int i=0; i+1 < s.length(); i++){
            if (s[i]=='+' && s[i+1] == '+'){
                string t = s;
                t[i] = '-';
                t[i+1] = '-';
                re.push_back(t);
            }
        }

        return re;
    }
};

int main(){
    return 0;
}