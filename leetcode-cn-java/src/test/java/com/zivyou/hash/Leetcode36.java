package com.zivyou.hash;

import com.zivyou.hash.leetcode36.Solution;
import org.junit.Test;

public class Leetcode36 {
    private final char[][] sodu1 = new char[][]{
            {'5','3','.','.','7','.','.','.','.'}
            ,{'6','.','.','1','9','5','.','.','.'}
            ,{'.','9','8','.','.','.','.','6','.'}
            ,{'8','.','.','.','6','.','.','.','3'}
            ,{'4','.','.','8','.','3','.','.','1'}
            ,{'2','.','.','.','2','.','.','.','6'}
            ,{'.','6','.','.','.','.','2','8','.'}
            ,{'.','.','.','4','1','9','.','.','5'}
            ,{'.','.','.','.','8','.','.','7','9'}
};

    @Test
    public void test01() {
        Solution solution = new Solution();
        System.out.println(solution.isValidSudoku(sodu1));
    }
}
