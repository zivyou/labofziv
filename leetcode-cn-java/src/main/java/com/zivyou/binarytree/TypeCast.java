package com.zivyou.binarytree;

@FunctionalInterface
public interface TypeCast<T> {
    T parseFromString(String data);
}
