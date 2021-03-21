#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        vector<int> carry(length+1, 0);
        vector<int> re(length, 0);
        digits[length-1]++;
        for (int i=length-1; i>=0; i--) {
            re[i] = (digits[i]+carry[i+1])%10;
            carry[i] = (digits[i]+carry[i+1])/10;
        }
        if (carry[0] > 0)
            re.insert(re.begin(), carry[0]);
        return re;
    }
};

int main(){
    return 0;
}