#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


class Solution {
public:
    void render(vector<vector<char> >& grid, int i, int j, int n){
        printf("i=%d, j=%d, n=%d\n", i, j, n);
        grid[i][j] = n;
        if (i > 0 && grid[i-1][j] == '1')
            render(grid, i-1, j, n);
        if ((j+1) < grid[i].size() && grid[i][j+1] == '1')
            render(grid, i, j+1, n);
        if ((i+1)<grid.size() && grid[i+1][j] == '1')
            render(grid, i+1, j, n);
        if (j > 0 && grid[i][j-1] == '1')
            render(grid, i, j-1, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        cout<<"grid.size()="<<grid.size()<<"grid[0].size()="<<grid[0].size()<<endl;
        int count = 0;
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[i].size(); j++){
                if (grid[i][j] == '1'){
                    render(grid, i, j, count+'2');
                    //cout<<count++<<endl;
                    count++;
                }
            }
        }

        return count;
    }
};


int main()
{
    ifstream f;
    f.open("data.txt", ios::in);
    vector<char> v;
    vector<vector<char> > data;
    while (!f.eof()){
        v.clear();
        string s;
        getline(f, s);
        if (f.eof())
            break;
        //cout<<"s="<<s<<endl;
        char c;
        for (int i=0; s[i]; i++){
            if (s[i] == '0' || s[i] == '1')
                v.push_back(s[i]);
        }
        data.push_back(v);
    }
    f.close();

    Solution sol;
    cout << sol.numIslands(data) << endl;
    return 0;
}
