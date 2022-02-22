package com.zivyou.string.leetcode08;

import java.util.Arrays;

/**
 * 教训:
 * 1. 字符串处理状态机；
 * 2. 在做溢出判断时花费了大量的时间，主要时re = re * 10 + c - '0';这个式子在每一步的时候都需要做溢出判断：
 *      1。 re * 10需要有两种场景的判断：re当前和int_max一样的位数的时候，*10会溢出；
 *      2。 re > int_max/10的时候，*10会溢出；
 * 3。式子的后半部分+c-'0'也需要做溢出判断，这个相对来说容易一些;
 */

public class Solution {
    private int result;
    private int sign = 1;
    private boolean overflow = false;
    private boolean calculate(int[] states, char c) {
        // 1,1,1    // 0,1,1    // 0,0,1
        if (states[1] == 0) {
            states[0] = 0;
        }

        if (states[2] == 0) {
            return false;
        }
        if (Arrays.equals(states, new int[]{1, 1, 1})) {
            if (c == ' ') {
               return true;
            } else {
                states[0] = 0;
                return calculate(states, c);
            }
        }

        if (Arrays.equals(states, new int[]{0, 1, 1})) {
            if (c == '+') {
                states[1] = 0;
                return true;
            }
            if (c == '-') {
                sign = -1;
                states[1] = 0;
                return true;
            }
            if (c >= '0' && c <= '9') {
                states[0] = 0; states[1] = 0;
                return calculate(states, c);
            }
            return false;
        }
        if (Arrays.equals(states, new int[]{0, 0, 1})) {
            if (sign > 0 && result >= Integer.MAX_VALUE) return true;
            if (result*sign <= Integer.MIN_VALUE) return true;
            if (!(c >= '0' && c <= '9')) return false;

            if (sign > 0) {
                if (Integer.MAX_VALUE - result <= 10) {
                    // 还没有*10就已经离max很近了
                    overflow = true;
                    return true;
                }
                if (Integer.MAX_VALUE / 10 < result) {
                    // 还没有*10就已经离min很近了
                    overflow = true;
                    return true;
                }
                //放心*10
                result = result * 10;
                if (Integer.MAX_VALUE - result <= c - '0') {
                    // *10后就已经离max很近了
                    overflow = true;
                    return true;
                }
                result += c - '0';
                return true;
            } else {
                if (Integer.MAX_VALUE - result  <= 10 - 1) {
                    // 还没有*10就已经离min很近了
                    overflow = true;
                    return true;
                }
                if (Integer.MAX_VALUE / 10 < result) {
                    // 还没有*10就已经离min很近了
                    overflow = true;
                    return true;
                }
                result = result * 10;
                if (Integer.MAX_VALUE - result  <= c - '0' - 1) {
                    // *10后就已经离min很近了
                    overflow = true;
                    return true;
                }
                result += c - '0';
                return true;
            }
        }
        return false;
    }

    public int myAtoi(String s) {
        if (s.length()<=0) return 0;
        char[] data = s.toCharArray();
        int[] states = new int[]{1, 1, 1}; // 可以去头' '；可以获取符号；可以算数
        for (int i=0; i<s.length(); i++) {
            if (!calculate(states, data[i])) break;
        }
        if (overflow) {
            if (sign > 0) return Integer.MAX_VALUE;
            else return Integer.MIN_VALUE;
        }
        return result*sign;
    }
}
