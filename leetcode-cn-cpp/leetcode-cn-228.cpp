#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> re;
        for (int i=0; i<nums.size(); i++){
            string s=std::to_string(nums[i]);
            int j=i;
            int begin = nums[j];
            int end = nums[j];
            while (j < nums.size()){
                if (j+1<nums.size() && nums[j+1] == nums[j]+1){
                    end = nums[j+1];
                }else
                    break;
                j++;
            }

            if (end > begin){
                s = s+"->"+std::to_string(end);
            }
            re.push_back(s);
            i = j;
        }

        return re;
    }
};

int main(){
    Solution s;
    vector<int> v({0,2,3,4,6,8,9, 13});
    vector<string> re = s.summaryRanges(v);
    for (int i=0; i<re.size(); i++){
        cout<<re[i]<<", ";
    }

    cout<<endl;
    return 0;
}