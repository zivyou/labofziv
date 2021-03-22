#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> data = heights;
        sort(data.begin(), data.end());
        int re = 0;
        for (int i=0; i<data.size(); i++){
            if (data[i] != heights[i])
                re++;
        }

        return re;
    }
};

int main(){
    return 0;
}