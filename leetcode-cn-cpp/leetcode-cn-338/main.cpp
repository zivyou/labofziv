#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> re;
        int i=1;
        int pre = 0;
        int preCount = 0;
        re.push_back(0);
        while (i <= num){
            if (i & 1){
                re.push_back(preCount+1);
                preCount++;
            }else{
                int j = i-1;
                while (j & 1){
                    preCount--;
                    j = j>>1;
                }
                preCount++;
                re.push_back(preCount);
            }
            pre = i;
            i++;
        }

        return re;
    }
};

int main()
{
    Solution s;
    vector<int> re = s.countBits(16);
    for (auto v : re)
        cout<<v<<" ";
    cout<<endl;
    return 0;
}
