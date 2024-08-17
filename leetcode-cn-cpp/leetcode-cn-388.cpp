#include <cstdio>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    string name;
    vector<TreeNode*> children;
    int level = 0;

    TreeNode(string& s, int l) {
        name = s;
        level = l;
    }
};

class Solution {
public:
    int lengthLongestPath(string input) {

    }
};


int main(int argc, char *argv[]) {

}
