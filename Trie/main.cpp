#include <iostream>
#include "Trie.hpp"

int main() {
  Trie* trie = new Trie();
  std::cout<<trie->prefix("ab")<<", "<<trie->search("ab")<<std::endl;
  trie->addString("abc");
  std::cout<<trie->prefix("ab")<<", "<<trie->search("abc")<<std::endl;
  delete trie;
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
