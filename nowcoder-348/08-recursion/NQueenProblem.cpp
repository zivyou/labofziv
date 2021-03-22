#include <iostream>
#include <cmath>

using namespace std;

class Solution {
private:
  // 要判断从[0...i-1]这些行上的皇后都和[i, j]这个皇后不冲突
  static bool isValid(const int* a, int i, int j) {
    for (int ii = 0; ii < i; ii++) {
      int x1 = ii; int y1 = a[ii];
      int x2 = i; int y2 = j;
      if (x1 == x2 || y1 == y2) return false;
      if( abs(x1 - x2) == abs(y1 - y2)) return false;
    }
    return true;
  }

  // 第[0...start-1]行的皇后都已经摆好了，它们不会互相冲突
  int process(int start, int* a, int n) {
    if (start >= n) {
      return 1;
    }
    int result = 0;
    for (int i=0; i<n; i++) {
      // 摆第start个皇后。我们每个列都试一下
      if (isValid(a, start, i)) {
        a[start] = i; // 为什么这里赋值不会污染全局已有的遍历过程？
                      // 其实是会污染的，所以最终a[]里面存储的数值并不是一个可行解
                      // a[]是被当作运行过程中一个临时的栈使用的，这个使用过程是我们的编译器和代码逻辑自动管理了
        cout<<"set "<<start<<" queen at column"<<i<<endl;
        result += process(start+1, a, n);
      }
    }

    return result;
  }
public:
  int nQueenProblem(int n) {
    if (n <= 1) return 0;
    int* a = new int[n]; // 第i行的皇后摆在第j列上，用a[i] = j记录

    int result = process(0, a, n);

    for (int i=0; i<n; i++) {
      cout<<a[i]<<", ";
    }
    cout<<endl;

    delete[] a;
    return result;
  }
};

int main() {
  Solution s;
  cout<<s.nQueenProblem(4)<<endl;
  return 0;
}