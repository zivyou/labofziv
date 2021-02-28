//
// Created by zivyou on 2021/2/28.
//

#ifndef TRIE_TRIE_HPP
#define TRIE_TRIE_HPP
#include <string>

class TrieNode {
private:
public:
  int p;
  int e;
  TrieNode* next[26*2];
  TrieNode() : p(0), e(0) {
    for (int i=0; i < 26*2; i++) next[i] = nullptr;
  };
  TrieNode(int a, int b) : p(a), e(b) {
    for (int i=0; i < 26*2; i++) next[i] = nullptr;
  };

  ~TrieNode() {
    for (int i=0; i < 26*2; i++) {
      if (next[i]) delete next[i];
    };
  }
};

class Trie {
private:
  TrieNode* root;
  int index (char c) {
    if (c>='a' && c<='z') return c-'a';
    if (c>='A' && c<='Z') return c-'A';
    return -1;
  }
public:
  Trie() {
    root = new TrieNode();
  }
  void addString(std::string str) {
    TrieNode* node = root;
    node->p++;
    for (auto c : str) {
      if (!node->next[index(c)]) {
        node->next[index(c)] = new TrieNode();
      }
      node = node->next[index(c)];
      node->p++;
    }
    node->e++;
  }

  int search(std::string str) {
    if (str.length() <= 0) return 0;
    TrieNode* node = root;
    for (auto c : str) {
      if (node->next[index(c)]) {
        node = node->next[index(c)];
      } else {
        return 0;
      }
    }
    return node->e;
  }

  int prefix(std::string str) {
    if (str.length() <= 0) return 0;
    TrieNode* node = root;
    for (auto c : str) {
      if (node->next[index(c)]) {
        node = node->next[index(c)];
      } else {
        return 0;
      }
    }
    return node->p;
  }
  ~Trie() {
    if (root) {
      delete root;
      root = nullptr;
    }
  }
};

#endif //TRIE_TRIE_HPP
