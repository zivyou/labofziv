//
// Created by zivyou on 2021/3/14.
//
/**
 * 背包问题，利用递归进行决策和回溯
 * 定义递归状态：process(index): 从当前index开始，后续自由选择所能获得的最大价值。这样process(0)即是全局解
 */

#include <iostream>

using namespace std;
class Solution {
private:
  int process(int w[], int v[], int index, int alreadyW, int bag, int length) {
    if (alreadyW > bag) {
      return -1;
    }
    if (index >= length) {
      return 0;
    }

    // 不选当前index货物
    int r1 = process(w, v, index+1, alreadyW, bag, length);

    // 选当前货物
    int r2 = -1;
    int rawR2 = process(w, v, index+1, alreadyW+w[index], bag, length);
    if (rawR2 != -1) {
      r2 = rawR2 + v[index];
    }
    return std::max(r1, r2);
  }
public:
  int BackPack(int w[], int v[], int bag, int N) {
    return process(w, v, 0, 0, bag, N);
  }
};

int main() {
  Solution s;
}