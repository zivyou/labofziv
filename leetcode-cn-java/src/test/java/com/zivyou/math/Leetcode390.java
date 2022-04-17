package com.zivyou.math;

import com.zivyou.math.leetcode390.Solution;
import org.junit.Test;

public class Leetcode390 {
    @Test
    public void test01() {
        Solution solution = new Solution();
        int i=0;
        while (i < 100) {
            System.out.println(solution.lastRemaining(i));
            i++;
        }
        System.out.println(solution.lastRemaining(100000000));
    }
}
