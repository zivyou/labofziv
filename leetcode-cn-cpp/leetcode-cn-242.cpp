#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char> v1(s.size());
        vector<char> v2(t.size());
        copy(s.begin(), s.end(), v1.begin());
        copy(t.begin(), t.end(), v2.begin());
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for (int i=0; i<v1.size() && i<v2.size(); i++){
            if (v1[i] != v2[i])
                return false;
        }

        return true;
    }
};

int main(){
    return 0;
}