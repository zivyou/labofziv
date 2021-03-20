/**
 * 扑克牌游戏：一组不重复的牌，摆成一列，两位选手依次选牌。选中的牌的点数即为获得的分值
 * 每位选手都只能从当前队列的头部或者尾部选牌。每位选手都聪明绝顶，他们会用最对自己有利的策略选牌
 * 求获胜者的分数
*/

#include <iostream>

using namespace std;

class Solution {
private:

  // 先手挑的情况下获得的最好分数
  int f(int list[], int L, int R) {
    if (L == R) {
      return list[L];
    }

    // 先手挑一个，要么L，要么R，挑完之后就是下一轮就是后手了
    return max(list[L] + s(list, L-1, R), list[R] + s(list, L, R-1));
  }

  // 后手挑的情况下获得的最好分数
  int s(int list[], int L, int R) {
    if (L >= R) return 0;

    // 后手挑，那么先手的人要么挑了L，要么挑了R。但是他挑完之后我们就变先手了
    return max(f(list, L-1, R), f(list, L, R-1));
  }

public:
  int PokerGame(int list[], int size) {
    return max(f(list, 0, size-1), s(list, 0, size-1));
  }
};

int main() {
  return 0;
}