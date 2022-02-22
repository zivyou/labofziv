package com.zivyou.string.leetcode06;

public class Solution {
    public String convert(String s, int numRows) {
        /**
         * 比较麻烦的点就是依据s.length()以及numRows计算出真实的numCols
         */
        if (numRows == 1) return s;
        if (numRows == 0) return "";
        int numUnit = s.length() / (numRows+numRows-2);
        int remain = s.length() % (2*numRows-2);
        int numCols = numUnit * (1+numRows-2);
        if (numCols == 0) numCols = 1;
        if (remain == 0) {
            // do nothing
        } else if (remain <= numRows) {
            numCols++;
        } else {
            numCols += remain - numRows;
        }
        System.out.println("numCols === "+numCols);
        char[][] results = new char[numRows][numCols];
        char[] data = s.toCharArray();
        if (numRows == 2) {
            StringBuffer sb = new StringBuffer();
            int at = 0;
            for (int i=0; i<numCols && at<s.length(); i++) {
                for (int j=0; j<numRows && at<s.length(); j++) {
                    results[j][i] = data[at++];
                }
            }
            for (char[] chars: results) {
                for (char c : chars)
                    if (c != 0)
                    sb.append(c);
            }
            return sb.toString();
        }
        int at = 0; int turn = 0; // 0往下; 1往上
        int j = 0;
        for (int i=0; i<numCols && at < s.length(); i++) {
            while (j<numRows && j>=0 && at<s.length()) {
                results[j][i] = data[at];
                at++;
                if (turn == 0) {
                    j++;
                } else {
                    j--;
                }
                if (j == numRows) {
                    turn = 1;
                    j-=2;
                    break;
                }
                if (j < 0) {
                    turn = 0;
                    j+=2;
                    break;
                }

            }
        }

        StringBuffer sb = new StringBuffer();
        for (char[] result : results) {
            for (char c: result) {
                if (0 != c) sb.append(c);
            }

        }
        return sb.toString();
    }
}
