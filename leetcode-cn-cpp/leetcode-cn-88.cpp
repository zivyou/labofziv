#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0){
            for (int j=0; j<n; j++){
                nums1[m++] = nums2[j];
            }
            return;
        }

        for (int j=0; j<n; j++){
            int i;
            for (i=m-1; i>=0; i--){
                if (nums2[j] > nums1[i]){
                    nums1[i+1] = nums2[j];
                    m++;
                    break;
                }else{
                    nums1[i+1] = nums1[i];
                }
            }
            if (i<0 && nums1[0] >= nums2[j]){
                nums1[0] = nums2[j];
                m++;
            }

            cout<<"m="<<m<<endl;
        }
    }
};

int main(){
    vector<int> nums1({-1,0,1,1,0,0,0,0,0});
    vector<int> nums2({-1,0,2,2,3});
    int m = 4;
    int n = 5;
    Solution s;
    s.merge(nums1, m, nums2, n);
    for (int i=0; i<nums1.size(); i++)
        cout<<nums1[i]<<" ";
    cout<<endl;

}