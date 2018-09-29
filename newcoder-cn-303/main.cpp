#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class NumArray {
private:
    vector<int> data;
    vector<vector<int>> re;
public:
    NumArray(vector<int> nums) {
        data = nums;
        int len = data.size();
        if (len > 0){
            int i = 0;
            for (i=0; i<len; i++){
                vector<int> temp(len, 0);
                re.push_back(temp);
            }
        }
    }

    int sumRange(int i, int j) {
        int len = data.size();
        int l = (i>=0?i:0);
        int r = (j<=len-1?j:len-1);
        if (l > r) return 0;
        if (re[l][r]) return re[l][r];
        if (l == r) {
            re[l][r] = data[l];
            return data[l];
        }else{
            if (re.size() == 0) return 0;


            int value=0;
            int mid = (l + r) / 2;

            value = sumRange(l, mid - 1) + data[mid] + sumRange(mid+1, r);
            return value;
        }
    }
};

int main() {
    vector<int> nums = {1, 4, -6};
    NumArray n(nums);

    std::cout << n.sumRange(0, 2) << std::endl;
    return 0;
}