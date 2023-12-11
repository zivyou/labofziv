package com.zivyou.katas;

import java.util.Arrays;

public class ConvertStringToCamelCase {
    static String toCamelCase(String s){
        String[] words = s.split("[-_]");
        for (int i=1; i<words.length; i++) {
            var w = new StringBuilder(words[i]);
            w.setCharAt(0, Character.toUpperCase(w.charAt(0)));
            words[i] = w.toString();
        }
        return String.join("", words);
    }
}
