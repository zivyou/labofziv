package com.zivyou.dualpointer.leetcode42;

public class Solution {
    public int trap(int[] height) {
        int left = 0;
        int right = 0;
        int result = 0;
        while (left < height.length && height[left] == 0) {
            left++;
        }
        right = left;
        while (left <= right && right < height.length) {
            // 先找第一个比left大的元素
            right++;
            while (right < height.length) {
                if (height[left] > height[right]) right++;
                else {
                    // 找到了，计算接水量
                    result += (right-left+1)*height[left];
                    for (int i=left; i<=right; i++) {
                        result -= Integer.min(height[i], height[left]);
                    }
                    left = right = right;
                    break;
                }
            }
            if (right == height.length) {
                // 没找到，不要放弃，将left重新设置起点
                left = right = left+1;
            }
        }
        right = left;
        while (left <= right && right < height.length) {
            // 先找到第一个比left小的元素
        }
        return result;
    }
}