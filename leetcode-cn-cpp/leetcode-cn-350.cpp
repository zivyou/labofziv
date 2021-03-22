#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();

        vector<int> re;
        int i, j;
        for (i=0; nums2.size() && i<nums1.size(); i++){
            for (j=0; nums1.size() && j<nums2.size(); j++){
                cout<<"i="<<i<<", j="<<j<<endl;
                if (nums1[i] == nums2[j]){
                    re.push_back(nums1[i]);
                    nums1.erase(nums1.begin()+i);
                    nums2.erase(nums2.begin()+j);
                    i--;
                    j--;
                }
            }
        }

        return re;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> re = s.intersect(nums1, nums2);

    for (auto num : re){
        cout<<num<<" ";
    }
    cout<<endl;
}