package com.zivyou.dp.leetcode377;

public class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] re = new int[target+1];
        for (int num : nums) {
            if (num <= target)
                re[num] = 1;
        }
        for (int current=0; current<=target; current++) {
            for (int num: nums) {
                if (num <= current) {
                    re[current] += re[current-num];
                }
            }
        }
        return re[target];
    }
}
