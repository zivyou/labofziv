#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    static int compare(const int &a, const int &b){
        if (a < b)
            return 1;
        else
            return 0;
    }

    static int vectorComp(const vector<int> &a, const vector<int> &b){
        for (int i=0; i<a.size(); i++){
            if (a[i]<b[i])
                return 1;
            else if (a[i] > b[i])
                return 0;
            else
                continue;
        }

        return 0;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), Solution::compare);
        int i, j, k;
        int length = nums.size();
        vector<vector<int>> re;
        vector<int> old = {-1, -1, -1};
        for (i=0; i<length-2; i++) {
            int sum = 0-nums[i];
            j=i+1; k=length-1;
            while (j<k){
                if (nums[j] + nums[k] > sum)
                    k--;
                else if (nums[j] + nums[k] < sum)
                    j++;
                else{
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    if (v[0] == old[0] && v[1]==old[1] && v[2]==old[2]){
                        j++;
                        k--;
                    }else {
                        re.push_back(v);
                        old = v;
                        j++;
                        k--;
                    }
                }
            }

        }
        if (re.size() <= 1)
            return re;
        sort(re.begin(), re.end(), Solution::vectorComp);

        vector<vector<int>>::iterator iteri;
        vector<vector<int>>::iterator iterj;
        for (iteri=re.begin(); iteri<re.end()-1; iteri++){
            for (iterj=iteri+1; iterj<re.end(); iterj++){
                if ((*iteri)[0] == (*iterj)[0] && (*iteri)[1]==(*iterj)[1] && (*iteri)[2]==(*iterj)[2]){
                    re.erase(iterj);
                    iterj--;
                }
            }
        }

        return re;
    }
};
int main() {
    vector<int> v = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    Solution s;
    vector<vector<int>> re = s.threeSum(v);
    for (int i=0; i<re.size(); i++) {
        for (int j = 0; j < re[i].size(); j++)
            cout << re[i][j]<<", ";
        cout<<endl;
    }
    return 0;
}