#include <iostream>
#include <vector>

using namespace std;

class Vector2D {
public:
    int x;
    int y;
    vector<vector<int>> data;
    Vector2D(vector<vector<int>>& v) {
        x = 0; y = 0;
        data = v;
    }
    
    int next() {
        if (y >= data[x].size()){
            x++;
            y = 0;
        }
        int re = data[x][y];
        y++;
        return re;
    }
    
    bool hasNext() {
        if (x >= data.size())
            return false;
        if (x == data.size() -1 && y >= data[x].size())
            return false;

        return true;
    }
};


int main(){
    return 0;
}