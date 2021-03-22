#include <iostream>

#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    static int compare(const int &a, const int &b){
        if (a<b)
            return 1;
        else
            return 0;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i, j, k, l;
        int len = nums.size();
        sort(nums.begin(), nums.end(), Solution::compare);
        vector<vector<int>> re;
        for (i=0; i<len-3; i++){
            for (j=i+1; j<len-2; j++){
                k=j+1; l=len-1;
                while (k<l){
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target){
                        vector<int> v = {nums[i], nums[j], nums[k], nums[l]};
                        re.push_back(v);
                        k++; l--;
                    }else if(nums[i] + nums[j] + nums[k] + nums[l] < target)
                        k++;
                    else
                        l--;
                }
            }
        }

        if (re.size() <= 1) return re;

        vector<vector<int>>::iterator iteri;
        vector<vector<int>>::iterator iterj;
        for (iteri=re.begin(); iteri<re.end()-1; iteri++)
            for (iterj=iteri+1; iterj<re.end(); iterj++){
                if ((*iteri)[0] == (*iterj)[0] && (*iteri)[1]==(*iterj)[1]
                    && (*iteri)[2]==(*iterj)[2]){
                    re.erase(iterj);
                    iterj--;
                }
            }

        return re;
    }
};



int main() {
    Solution s;
    vector<int> v = {-3, -2, -1, 0, 0, 1, 2, 3};
    vector<vector<int>> re = s.fourSum(v, 0);
    for (int i=0; i<re.size(); i++){
        for (int j=0; j<4; j++)
            cout<<re[i][j]<<" ";
        cout<<",   ";
    }
    cout<<endl;
    return 0;
}