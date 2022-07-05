package com.zivyou.string.leetcode394;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

public class Solution {
    public String decodeString(String s) {
        Stack<Integer> repeatCount = new Stack<>();
        List<StringBuilder> repeatedString = new ArrayList<>();

        StringBuilder sb = null;
        for (char c : s.toCharArray()) {
            if (c>='0' && c<='9') {
                repeatCount.push(c - '0');
            } else if (c == '[') {
                sb = null;
            } else if (c == ']') {
                if (sb == null) {
                    sb = repeatedString.remove(repeatedString.size()-1);
                }
                Integer count = repeatCount.pop();
                StringBuilder tmpResult = new StringBuilder();
                for (int i=0; i<count; i++) {
                    tmpResult.append(sb);
                }
                repeatedString.add(tmpResult);
                sb = null;
            } else if (c>='a' && c<='z') {
                if (sb == null) sb = new StringBuilder();
                sb.append(c);
            } else {
                return "";
            }
        }

        StringBuilder result = new StringBuilder();
        for (StringBuilder stringBuilder : repeatedString) {
            result.append(stringBuilder);
        }
        if (sb != null) result.append(sb);
        return result.toString();
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.decodeString("4[b]2[3[a]]"));
        String result = s.decodeString("2[abc]3[cd]ef");
        System.out.println(result);
        result = s.decodeString("3[a]2[bc]");
        System.out.println(result);
        result = s.decodeString("3[a2[c]]");
        System.out.println(result);
        result = s.decodeString("abc3[cd]xyz");
        System.out.println(result);

    }
}
