#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int begin=0;
        int j=0;
        for (begin=0; begin<(int)(s.size()); begin++){
            for (j=begin+1; j<(int)s.size(); j++){
                if (s.substr(begin, j-begin).find_first_of(s[j]) != -1)
                    break;
            }
            if (j-begin > max)
                max = j-begin;
        }

        return max;
    }
};

int main() {
    Solution s;
    cout<<s.lengthOfLongestSubstring(" ")<<endl;
    return 0;
}