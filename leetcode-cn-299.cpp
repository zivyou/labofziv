#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int> m;
        for (auto c : guess){
            if (m.find(c) == m.end())
                m[c] = 1;
            else
                m[c] = m[c]+1;
        }

        int A = 0; int B = 0;
        map<char, int> m2;
        for (auto c : secret){
            if (m2.find(c) == m2.end())
                m2[c] = 1;
            else
                m2[c] = m2[c]+1;
        }

        for (int i=0; i<secret.size(); i++)
            if (secret[i] == guess[i]){
                A++;
                m2[secret[i]]--;
                m[secret[i]]--;
            }

        for (auto pair : m2){
            if (m.find(pair.first) != m.end()){
                B = B + min(pair.second, m[pair.first]);
            }
        }

        return std::to_string(A)+"A"+std::to_string(B)+"B";
    }
};

int main(){
    Solution s;
    cout<<s.getHint("1123", "0111")<<endl;
    return 0;
}