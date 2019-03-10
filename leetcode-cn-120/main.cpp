#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() <= 0)
            return 0;
        int **dp = new int*[triangle.size()+1];
                cout<<"OK"<<endl;

        for (int i=0; i<triangle.size(); i++){
            dp[i] = new int[triangle[i].size()];
        }
        dp[triangle.size()] = new int[triangle[triangle.size()-1].size()+1];

        for (int i=0; i<=triangle[triangle.size()-1].size(); i++)
            dp[triangle.size()][i] = 0;
        for (int i=triangle.size()-1; i>=0; i--)
            for (int j=triangle[i].size()-1; j>=0; j--)
            if (dp[i+1][j] > dp[i+1][j+1])
                dp[i][j] = dp[i+1][j+1] + triangle[i][j];
            else
                dp[i][j] = dp[i+1][j] + triangle[i][j];
        return dp[0][0];
    }
};

int main()
{
    vector<vector<int>> triangle;
    triangle.push_back(vector<int>({2}));
    triangle.push_back(vector<int>({3,4}));
    triangle.push_back(vector<int>({6,5,7}));
    triangle.push_back(vector<int>({4,1,8,3}));

    Solution s;
    cout<<s.minimumTotal(triangle)<<endl;
    return 0;
}
