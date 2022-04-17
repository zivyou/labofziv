package com.zivyou.basic.leetcode393;

public class Solution {
    private int getType(byte b) {
        if ((b & (1<<7)) == 0) return 0; // 单字节
        if ((b & 0xC0) == 0x80) return -1; // 小弟
        for (int i=1; i<=8; i++) {
            if ((b & (1<<(8-i))) == 0) return i-1;
        }
        return 9;
    }
    public boolean validUtf8(int[] data) {
        byte[] bytes = new byte[data.length];
        for (int i=0; i<data.length; i++) {
            bytes[i] = (byte) (data[i] & 0xFF);
        }

        int i=0;
        /*
        0: 期待单字节或者大哥；
        n: 期待n个小弟;
         */
        int state = 0;
        while (i < bytes.length) {
            int type = getType(bytes[i]);
            if (type == 9) return false;
            if (type >= 5) return false;
            if (state == 0) {
                if (type > 0) {
                    state = type-1;
                } else if (type == 0){
                   // do nothing
                }  else return false;
            } else {
                if (type >= 0) return false;
                state--;
            }
            i++;
        }
        return state <= 0;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.validUtf8(new int[]{13,10}));
    }
}
