package com.zivyou.katas;

import org.junit.Test;

import java.util.Arrays;

import static org.junit.Assert.assertEquals;

public class SpinWordsTest {
    @Test
    public void test() {
        assertEquals("emocleW", new SpinWords().spinWords("Welcome"));
        assertEquals("Hey wollef sroirraw", new SpinWords().spinWords("Hey fellow warriors"));
    }

    @Test
    public void test02() {
        System.out.println(new SpinWords().spinWords("Welcome"));
    }

}
