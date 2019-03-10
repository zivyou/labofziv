#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int getNumber(vector<int> v, int pos){
        if (pos < 0)
            return 0;
        if (pos >= v.size())
            return 0;
        return v[pos];

    }

    vector<int> getRow(int index) {
        int rowIndex = index+1;
        vector<int> re;
        if (rowIndex <= 0)
            return re;
        re.push_back(1);
        if (rowIndex == 1)
            return re;
        for (int i=2; i<=rowIndex; i++){
            vector<int> newV;
            for (int j=0; j<i; j++)
                newV.push_back(getNumber(re, j-1)+getNumber(re, j));
            //newV.push_back(1);
            re = newV;
        }

        return re;
    }
};


int main()
{
    Solution s;
    vector<int> v = s.getRow(3);
    for (int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    return 0;
}
