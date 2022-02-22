package com.zivyou.string.manacher;

import com.zivyou.string.manacher.leetcode05.Solution;
import org.junit.Test;

public class Leetcode05 {
    @Test
    public void test() {
        String s = "baxxac";
        Solution solution = new Solution();
        System.out.println(solution.longestPalindrome(s));
    }
}
