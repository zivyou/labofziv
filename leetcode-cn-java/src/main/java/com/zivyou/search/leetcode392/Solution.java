package com.zivyou.search.leetcode392;

public class Solution {

    private boolean rawIsSubsequence(char[] s, int i, char[] t, int j, int[] next) {
        if (i >= s.length) return true;
        if (j >= t.length) return false;
        if (s[i] == t[j]) {
            if (rawIsSubsequence(s, i+1, t, j+1, next)) return true;
            else  return rawIsSubsequence(s, i, t, next[j], next);
        }
        return rawIsSubsequence(s, i, t, j+1, next);
    }

    public boolean isSubsequence(String s, String t) {
        char[] ss = s.toCharArray();
        char[] tt = t.toCharArray();
        int[] nextt = new int[t.length()];
        for (int i=0; i<tt.length; i++) {
            boolean found = false;
            for (int j=i+1; j<tt.length; j++) {
                if (tt[i] == tt[j]) {
                    nextt[i] = j;
                    found = true;
                    break;
                }
            }
            if (!found) nextt[i] = tt.length;
        }
        return rawIsSubsequence(ss, 0, tt, 0, nextt);
    }

    public static void main(String[] args) {
        String s = "aaaaaa";
        String t = "bbaaaa";
        Solution solution = new Solution();
        System.out.println(solution.isSubsequence(s, t));
    }
}
