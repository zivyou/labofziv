package com.zivyou.math.leetcode390;

public class Solution {
    public int lastRemaining(int n) {
        int count = n;
        int leftBegin = 1;
        int rightBegin = n;
        int turn = 1;
        while (count > 1) {
            if (turn % 2 > 0) {
                leftBegin = leftBegin + (1<<(turn-1));
                if (count % 2 == 1) {
                    rightBegin = rightBegin - (1<<(turn-1));
                } else {
                    rightBegin = rightBegin;
                }
            } else {
                rightBegin = rightBegin-(1<<(turn-1));
                if (count % 2 == 1) {
                    leftBegin = leftBegin + (1<<(turn-1));
                } else {
                    leftBegin = leftBegin;
                }
            }
            turn++;
            count = count/2;
        }
        if (turn % 2 == 1) return leftBegin;
        else return rightBegin;
    }
}