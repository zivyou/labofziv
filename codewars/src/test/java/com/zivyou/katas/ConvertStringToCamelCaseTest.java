package com.zivyou.katas;

import org.junit.Test;

import java.util.Locale;

import static org.junit.Assert.assertEquals;

public class ConvertStringToCamelCaseTest {
    @Test
    public void test01() {
        System.out.println("hello".toUpperCase());
    }

    @Test
    public void testSomeUnderscoreLowerStart() {
        String input = "the_Stealth_Warrior";
        System.out.println("input: "+input);
        assertEquals("theStealthWarrior", ConvertStringToCamelCase.toCamelCase(input));
    }
    @Test
    public void testSomeDashLowerStart() {
        String input = "the-Stealth-Warrior";
        System.out.println("input: "+input);
        assertEquals("theStealthWarrior", ConvertStringToCamelCase.toCamelCase(input));
    }
}
