#include <iostream>
#include <vector>

using namespace std;


class NumArray {
private:
    vector<int> data;
    vector<int> re;
public:
    NumArray(vector<int>& nums) {
        data = nums;
        if (data.size() < 1) return;
        re = nums;
        for(int i=1; i<data.size(); i++)
            re[i] = re[i-1] + data[i];
    }
    int sumRange(int i, int j) {
        if (i == j)
            return data[j];
        return re[j] - re[i] + data[i];
    }
};



int main(){
    vector<int> v = {-2, 0, 3, -5, 2, -1};
    NumArray na(v);
    cout<<na.sumRange(0,5)<<endl;
    return 0;
}