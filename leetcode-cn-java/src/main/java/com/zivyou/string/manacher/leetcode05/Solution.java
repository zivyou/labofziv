package com.zivyou.string.manacher.leetcode05;


/**
 * 两种子情况：
 * 1。 奇数扩张
 * 2。 偶数扩张
 */

public class Solution {
    public String longestPalindrome(String s) {
        char[] str = s.toCharArray();

        int begin=0; int end=0;
        for (int i=0; i<s.length(); i++) {
            // 奇数扩张
            int k=0;
            while (i-k>=0 && i+k<s.length() && str[i-k]==str[i+k]) {
               k++;
            }
            if (2*k-1 > end-begin+1) {
                begin = i-k+1;
                end = i+k-1;
            }
            // 偶数扩张
            k=0;
            while (i-k>=0 && i+k+1<s.length() && str[i-k]==str[i+k+1]) {
                k++;
            }
            if (2*k > end-begin+1) {
                begin = i-k+1;
                end = i+k;
            }
        }
        return s.substring(begin, end+1);
    }
}
