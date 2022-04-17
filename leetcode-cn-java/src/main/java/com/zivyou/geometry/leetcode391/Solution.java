package com.zivyou.geometry.leetcode391;

import java.util.Arrays;

public class Solution {
    private int[] rightDown(int[] a) {
        int[] result = new int[2];
        result[0] = a[2];
        result[1] = a[1];
        return result;
    }
    private int[] leftDown(int[] a) {
        int[] result = new int[2];
        result[0] = a[0];
        result[1] = a[1];
        return result;
    }

    private int[] rightUp(int[] a){
        int[] result = new int[2];
        result[0] = a[1];
        result[1] = a[3];
        return result;
    }

    private int[] leftUp(int[] a) {
        int[] result = new int[2];
        result[0] = a[0];
        result[1] = a[3];
        return result;
    }
    private int located(int[] a, int[] b) {
//        if (a[3] < b[1]) return 1;
//        if (b[3] < a[1]) return 1;
//        if (a[2] < b[0]) return 1;
//        if (b[2] < a[0]) return 1;
        if (Arrays.equals(rightDown(a), leftDown(b))) return -1;
        if (Arrays.equals(rightDown(a), rightUp(b))) return 1;
        if (rightUp(a).equals(rightDown(b))) return -1;
        if (Arrays.equals(rightUp(a), leftUp(b))) return -1;
        if (leftUp(a).equals(leftDown(b))) return -1;
        if (leftUp(a).equals(rightUp(b))) return 1;
        if (leftDown(a).equals(rightDown(b))) return 1;
        if (leftDown(a).equals(leftUp(b))) return -1;

        return 0;
    }

    private boolean lessThan(int[] a, int[] b) {
        return false;
    }

    public boolean isRectangleCover(int[][] rectangles) {
        return false;
    }
}
