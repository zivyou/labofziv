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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> re;
        if (numRows <= 0)
        return re;
        vector<int> origin({1});
        re.push_back(origin);
        for (int i=2; i<=numRows; i++){
            vector<int> newV;
            for (int j=0; j<i; j++)
                newV.push_back(getNumber(re[re.size()-1], j-1)+getNumber(re[re.size()-1], j));
            //newV.push_back(1);
            re.push_back(newV);
        }
        return re;

    }
};

int main()
{
    vector<vector<int>> re;
    Solution s;
    re = s.generate(5);
    for (int i=0; i<re.size(); i++){
        for (int j=0;  j<re[i].size(); j++)
            cout<<re[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
