//
// Created by zivyou on 2021/2/28.
//

#ifndef TRIE_TRIE_HPP
#define TRIE_TRIE_HPP
#include <string>

class TrieNode {
private:
public:
  int p; // 中途路过
  int e; // 以。。为结尾
  TrieNode* next[26*2] = {nullptr};
  TrieNode() : p(0), e(0) {
    for (auto & i : next) i = nullptr;
  };
  TrieNode(int a, int b) : p(a), e(b) {
    for (auto & i : next) i = nullptr;
  };

  ~TrieNode() {
    for (auto & i : next) {
      delete i;
    };
  }
};

class Trie {
private:
  TrieNode* root;
  static int index (char c) {
    if (c>='a' && c<='z') return c-'a';
    if (c>='A' && c<='Z') return c-'A';
    return -1;
  }
public:
  Trie() {
    root = new TrieNode();
  }
  void addString(const std::string& str) {
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

  int search(const std::string& str) {
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

  int prefix(const std::string& str) {
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
