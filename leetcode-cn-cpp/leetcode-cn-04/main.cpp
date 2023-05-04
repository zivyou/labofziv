#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
private:
    double rawMedian(vector<int>& nums, int l, int r) {
        if ((r-l+1)%2 == 0) {
            return (nums[l+(r-l+1)/2] + nums[l+(r-l+1)/2-1])*1.0f/2.0f;
        } else {
            return nums[(l+r)/2]*1.0f;
        }
    }
    double rawFind(vector<int>& nums1, int l1, int r1, vector<int>& nums2, int l2, int r2) {
        printf("l1=%d, r1=%d, l2=%d, r2=%d \n", l1, r1, l2, r2);
//        if (l1 == r1 && l2 == r2) {
//            return (nums1[l1]+nums2[l2])*1.0f/2.0f;
//        }
        if (l1 > r1 && l2 <= r2) {
            return rawMedian(nums2, l2, r2);
        }
        if (l1 <= r1 && l2 > r2) {
            return rawMedian(nums1, l1, r1);
        }
        int count1 = r1 - l1 + 1; int count2 = r2-r2+1;
        if (count1 % 2 == 1 && count2 % 2 == 1) {
            int mid1 = (l1+r1)/2; int mid2 = (l2+r2)/2;
            if (nums1[mid1] <= nums2[mid2]) {
                return rawFind(nums1, mid1+1, r1, nums2, l2, mid2);
            } else {
                return rawFind(nums2, mid2+1, r2, nums1, l1, mid1);
            }
        } else if (count1%2==0 && count2%2==1) {
            int left1Num = nums1[l1+count1/2-1];
            int right1Num = nums1[l1 + count1 / 2];
            int mid2Num = nums2[(l2+r2)/2];
            if (left1Num<=mid2Num && mid2Num <= right1Num) return mid2Num;
            if (mid2Num <= left1Num)
                return rawFind(nums2, (l2+r2)/2, r2, nums1, l1, l1+count1/2);
            if (right1Num <= mid2Num)
                return rawFind(nums1, (l1+count1/2-1), r1, nums2, l2, (l2+r2)/2);
        } else if (count1%2==1 && count2%2==0) {
            int mid1Num = nums1[(l1+r1)/2];
            int left2Num = nums2[l2+(count2)/2-1];
            int right2Num = nums2[l2+(count2)/2];
            if (mid1Num <= left2Num)
                return rawFind(nums1, (l1+r1)/2, r1, nums2, l2, l2+(count2)/2-1);
            if (left2Num <= mid1Num && mid1Num <= right2Num)
                return mid1Num;
            if (right2Num <= mid1Num) {
                return rawFind(nums2, l2+count2/2-1, r2, nums1, l1, (l1+r1)/2);
            }
        } else {
            int left1 = l1+count1/2-1; int right1 = left1+1;
            int left2 = l2+count2/2-1; int right2 = left2+1;
            if (nums1[left1] <= nums2[left2] && nums2[right2] <= nums1[right1])
                return (nums2[left2] + nums2[right2])*1.0f/2.0f;
            if (nums2[left2] <= nums1[left1] && nums2[right2] <= nums1[right1])
                return (nums1[left1] + nums1[right1])*1.0f/2.0f;
            if (nums1[left1] <= nums2[left2] && nums1[right1] <= nums2[right2])
                return rawFind(nums1, left1, r1, nums2, l2, right2);
            if (nums2[left2] <= nums1[left1] && nums2[right2] <= nums1[right1])
                return rawFind(nums2, left2, r2, nums1, l1, right1);
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return rawFind(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1);
    }
};

int main() {
    Solution s;
    cout<<s.findMedianSortedArrays(*new vector<int>({1, 2}), *new vector<int>({3, 4}))<<endl;
    return 0;
}