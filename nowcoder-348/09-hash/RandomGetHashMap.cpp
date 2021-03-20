/**
 * 设计一个数据结构，支持get(key), set(key), getRandom()方法，
 * 并且要求这3个方法的时间复杂度都为O(1)
 */


#include <iostream>
#include <unordered_map>
#include <random>

using namespace std;

class RandomHashMap {
private:
  unordered_map<int, string> map1;
  unordered_map<string, int> map2;
public:
  string get(int key) {
    if (map1.find(key) == map1.end()) return string();
    return map1[key];
  }

  void set(int key, const string& value) {
    if (map1.find(key) != map1.end()) return;
    map1[key] = value;
    map2[value] = key;
  }

  void remove(int key) {
    if (map1.find(key) != map1.end()) return;
    string v2 = map1[key];
    string map2End = map2.end()->first;
    map1[key] = map1.end()->second;
    map2[map2End] = key;
    map1.erase(map1.end());
    map2.erase(map2.end());
  }

  string randomGet() {
    default_random_engine e;
    int size = map1.size();
    return map1[e() % size];
  }
};

int main() {
  return 0;
}