#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int N;
    int result;
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


    void dfs(vector<int>& pos, int current){
        if (!isNormal(pos))
            return;
        if (current > N)
            return;
        if (pos.size()==N){
            result++;
            return;
        }
        
        for (int i=0; i<N; i++){
            pos.push_back(i);
            dfs(pos, current+1);
            pos.pop_back();
        }
    }
    int totalNQueens(int n) {
        vector<int> pos;
        N = n;
        result = 0;
        dfs(pos, 0);
        return result;
    }   
};

int main(){
    Solution s;
    cout<<s.totalNQueens(4)<<endl;
}
