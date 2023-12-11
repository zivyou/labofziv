package com.zivyou.katas;

public class SpinWords {
    private String autoReverseWord(String word) {
        var length = word.length();
        if (length < 5) return word;
        char[] chs = new char[length];
        for (int i=0; i<length; i++) {
            chs[i] = word.charAt(length-i-1);
        }
        return new String(chs);
    }
    public String spinWords(String sentence) {
        String[] words = sentence.split(" ");
        for (int i=0; i<words.length; i++) {
            if (words[i].length() < 5) continue;
            words[i] = autoReverseWord(words[i]);
        }
        return String.join(" ", words);
    }
}
