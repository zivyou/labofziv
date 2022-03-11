package com.zivyou.hash.leetcode389;

public class Solution {
    public char findTheDifference(String s, String t) {
        final int[] count = new int[27];
        for (char c : s.toCharArray()) {
            count[c-'a']++;
        }
        final int[] count2 = new int[27];
        for (char c : t.toCharArray()) {
            count2[c-'a']++;
        }

        for (char c : t.toCharArray()) {
            if (count[c-'a'] + 1 == count2[c-'a']) return c;
        }
        return 0;
    }
}
