#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0; int j=s.size()-1;
        while (i <= j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
