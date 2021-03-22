#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int getNum(int x, int y, int n){
        int re = 0;
        int min = x;
        if (n-x-1 < min)
            min = n-x-1;
        if (y < min)
            min = y;
        if (n-y-1 < min)
            min = n-y-1;
        
        int Sn = 4*n*min - 4*min*min;
        //cout<<"min = "<<min<<", Sn="<<Sn<<endl;
        re = re+Sn;

        if (x == min){
            re = re + y + 1 - min; 
            return re;
        }
        if (y == n-1-min){
            re = re + n -2*min - 1;
            re = re + x + 1 - min ;
            return re;
        }

        if (x == n-1-min){
            re = re + n - 2*min - 1;
            re = re + n - 2*min - 1;
            re = re + (n - y) - min;
            return re;
        }


        if (y == min){
            re = re + n - 2*min - 1;
            re = re + n - 2*min - 1;
            re = re + n - 2*min - 1;
            re = re + (n - x) - min;
            return re;
        }

        return -1;
    }

    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > re;
        for (int i=0; i<n; i++){
            vector<int> v;
            for (int j=0; j<n; j++)
                v.push_back(getNum(i, j, n));
            re.push_back(v);
        }

        return re;
    }
};

int main(){
    Solution s;
    cout<<s.getNum(4, 4, 3)<<endl;
}