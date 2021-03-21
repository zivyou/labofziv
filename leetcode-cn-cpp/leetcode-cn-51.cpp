#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int N;
    vector<vector<string> > result;
    bool isNormal(vector<int>& pos){
        if (pos.size() <= 1)
            return true;
        int lastOne = pos[pos.size()-1];
        for (int i=0; i<pos.size()-1; i++){
            if (lastOne == pos[i])
                return false;
            if (abs(lastOne-pos[i])%(pos.size()-1-i) == 0 && abs(lastOne-pos[i])/(pos.size()-1-i) == 1)
                return false;
            if (abs(lastOne-pos[i])%(pos.size()-1-i) == 0 && abs(lastOne-pos[i])/(pos.size()-1-i) == -1)
                return false;
        }
        return true;
    }

    void printResult(vector<int>& pos){
        vector<string> oneResult;
        for (int i=0; i<N; i++){
            string oneLine(N, '.');
            oneLine[pos[i]] = 'Q';
            oneResult.push_back(oneLine);
            
        }  
        result.push_back(oneResult);
    }

    void dfs(vector<int>& pos, int current){
        if (!isNormal(pos))
            return;
        if (current > N)
            return;
        if (pos.size()==N){
            printResult(pos);
            return;
        }
        
        for (int i=0; i<N; i++){
            pos.push_back(i);
            dfs(pos, current+1);
            pos.pop_back();
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<int> pos;
        N = n;
        dfs(pos, 0);
        return result;
    }   
};

int main(){
    Solution s;
    vector<vector<string> > results = s.solveNQueens(5);
    for (int i=0; i<results.size(); i++){
        for (int j=0; j<results[i].size(); j++)
            cout<<results[i][j]<<endl;;
        cout<<"==========="<<endl;
    }
}
