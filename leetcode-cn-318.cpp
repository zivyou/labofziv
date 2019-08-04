#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static int cmp(string &a, string &b){
        if (a.length() <= b.length())
            return 0;
        else
        {
            return 1;
        }
        
    }
    int mul(string a, string b){
        for (auto c : b){
            if (a.find(c) != std::string::npos)
                return 0;
        }
        return a.length() * b.length();
    }
    int maxProduct(vector<string>& words) {
        sort(words.begin(), words.end(), Solution::cmp);
        int max = 0;
        for (int i=0; i<words.size(); i++){
            for (int j=i+1; j<words.size(); j++){
                if (words[i].length() * words[j].length() < max)
                    continue;
                int re = mul(words[i], words[j]);
                if (re > max){
                    max = re;
                }
            }
        }

        return max;
    }
};

int main(){
    return 0;
}