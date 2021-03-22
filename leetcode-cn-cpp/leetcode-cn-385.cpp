#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isIntegerSign() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedInteger {
private:
  bool isIntegerSign;
  int val;
  vector<NestedInteger> data;
public:
    // Constructor initializes an empty nested list.
    NestedInteger() {
      isIntegerSign = false;
    }

    // Constructor initializes a single integer.
    NestedInteger(int value) {
      val = value;
      isIntegerSign = true;
    }
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {
      return isIntegerSign;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
      return val;
    }

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) {
      val = value;
    }

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni) {
      data.push_back(ni);
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
      return data;
    }
};

class Lexer {
private:
  string str_;
  string data_;
  stack<NestedInteger*> st_;
  bool open;
public:
  Lexer(string s) {
    data_ = s;
    open = false;
  }

  NestedInteger analyse() {
    for (auto c : data_) {
      if ((c >= '0' && c <= '9') || c == '-') {
        str_.push_back(c);
      } else if (c == '[') {
        st_.push(new NestedInteger());
      } else if (c == ']') {
        if (str_.length()) {
          int num = stoi(str_);
          str_.clear();
          st_.top()->add(*new NestedInteger(num));
        }
        NestedInteger* t = st_.top();
        st_.pop();
        if (st_.empty()) {
          return *t;
        } else {
          st_.top()->add(*t);
        }
      } else if (c == ',') {
        if (str_.length()) {
          int num = stoi(str_);
          st_.top()->add(*new NestedInteger(num));
          str_.clear();
        }
      } else {
        // do nothing
      }
    }
    if (st_.empty() && str_.length()) {
      int num = stoi(str_);
      return *new NestedInteger(num);
    }
    return *st_.top();
  }
};

class Solution {
public:
  NestedInteger deserialize(string s) {
    Lexer lexer(s);
    return lexer.analyse();
  }
};

int main() {
  Solution s;
  NestedInteger re = s.deserialize("[123,456,[788,799,833],[[]],10,[]]");
  return 0;
}
