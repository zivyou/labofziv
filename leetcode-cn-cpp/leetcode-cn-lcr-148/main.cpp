#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateBookSequences(vector<int>& putIn, vector<int>& takeOut) {
        stack<int> st; int i=0; int j=0;
        while (i < putIn.size() && j<takeOut.size()) {
            while (!st.empty() && st.top() == takeOut[j]) {
                st.pop(); j++;
            }
            {
                st.push(putIn[i]);
                i++;
            }
            while (!st.empty() && st.top() == takeOut[j]) {
                st.pop(); j++;
            }
        }
        // printf("stack size is : %d\n", st.size());
        return st.empty();
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> v1 = {0};
    vector<int> v2 = {0};
    printf("%d\n", s.validateBookSequences(v1, v2));
}
