#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, bool> count;  
        for (auto c: s){
            count[c] = true;
        }

        for (auto c : s){
            count[c] = !count[c];
        }
        
        int amount = 0;
        for (auto pair : count){
            if (!pair.second)
                amount++;
        }
        return amount <= 1;
    }
};

int main(){
    return 0;
}