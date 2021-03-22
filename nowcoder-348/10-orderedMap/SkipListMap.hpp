/**
 * 跳表：是一种针对链表建立多层索引的结构
*/

/**
*   ____
*  |   |----------------------------->-----
 * |   |                              |   |
 * |   |                              |   |
 * |   |       ___                    |   |
 * |   |----->|   |------------------>|   |
   ----       ----                    ----
*/

#include <vector>
#include <random>
template<typename K, typename V>
struct Node {
  std::vector<Node<K, V>*> nexts;
  K key;
  V value;
};

template<typename K, typename V>
class SkipListMap {
private:
  std::vector<Node<K, V>*> headArray;
  int roll() {
    std::default_random_engine dre;
    const int value = dre() % 10;
    if (value > 5) {}
  }
public:
  void put(K key, V value) {

  }
};