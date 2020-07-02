#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <map>

using namespace std;

class RandomizedSet {
private:
  map<int, int> indexes;
  vector<int> data;
  int pos;
  unsigned int seed;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
      seed = time(NULL);
      srand(seed);
      pos = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
      if (indexes.find(val) != indexes.end()) {
        return false;
      }
      data.push_back(val);
      indexes[val] = pos;
      pos++;
      return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
      if (data.size() < 1) return false;
      if (indexes.find(val) != indexes.end()) {
        int t = data[data.size() - 1];
        data[data.size()-1] = data[indexes[val]];
        // cout<<"index: "<<indexes[val]<<endl;
        data[indexes[val]] = t;
        indexes[t] = indexes[val];
        data.erase(data.end()-1);
        indexes.erase(val);
        pos--;
        return true;
      }
      return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
      int range = data.size();
      int random = rand();
      int index = random % range;
      auto it = data.begin();
      int val = *(it + index);
      return val;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
  RandomizedSet set;
  set.insert(1);
  set.insert(2);
  set.insert(3);
  set.insert(4);
  set.remove(4);
  cout<<set.getRandom()<<endl;
}