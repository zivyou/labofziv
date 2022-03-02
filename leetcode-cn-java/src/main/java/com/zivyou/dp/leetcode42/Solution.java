package com.zivyou.dp.leetcode42;

public class Solution {
    public int trap(int[] height) {
        int[] left = new int[height.length];
        int[] right = new int[height.length];

        for (int i=0; i<height.length; i++) {
            if (i == 0) {
                left[i] = height[i];
                continue;
            }
            left[i] = Integer.max(left[i-1], height[i]);
        }

        for (int j = height.length-1; j>=0; j--) {
            if (j == height.length - 1) {
                right[j] = height[j];
                continue;
            }
            right[j] = Integer.max(right[j+1], height[j]);
        }
        int result = 0;
        for (int i=0; i<height.length; i++) {
            int maxLeft = left[i];
            int maxRight = right[i];
            int depth = Integer.min(maxLeft, maxRight);
            result += (depth > height[i]) ? depth - height[i] : 0;
        }
        return result;
    }
}
