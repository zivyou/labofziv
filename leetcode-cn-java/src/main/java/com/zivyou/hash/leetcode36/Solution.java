package com.zivyou.hash.leetcode36;

public class Solution {
    private boolean isRowValid(char[][] board, int row) {
        int[] exists = new int[10];
        for (int i=0; i<9; i++) {
            if (board[row][i] != '.') {
                int num = board[row][i] - '0';
                if (exists[num] != 0) return false;
                else exists[num] = 1;
            }
        }
        return true;
    }

    private boolean isColValid(char[][] board, int col) {
        int[] exists = new int[10];
        for (int i=0; i<9; i++) {
            if (board[i][col] != '.') {
                int num = board[i][col] - '0';
                if (exists[num] != 0) return false;
                else exists[num] = 1;
            }
        }
        return true;
    }

    private boolean isPartValid(char[][] board, int x, int y) {
        // x,y为左上角
        int[] exists = new int[10];
        for (int i=x; i<x+3; i++) {
            for (int j=y; j<y+3; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (exists[num] != 0) {
                        System.out.println("part "+x+" ,"+y+" is not valid: "+num);
                        return false;
                    }
                    else exists[num] = 1;
                }
            }
        }
        return true;
    }
    public boolean isValidSudoku(char[][] board) {
        int n = board.length;
        for (int i=0; i<n; i++) {
            if (!isColValid(board,i)) {
                System.out.println("col "+i+" is not valid");
                return false;
            }
            if (!isRowValid(board, i)) {
                System.out.println("row "+i+" is not valid");
                return false;
            }
        }

        for (int i=0; i<9; i+=3)
            for (int j=0; j<9; j+=3)
                if (!isPartValid(board, i, j)) return false;
        return true;
    }
}