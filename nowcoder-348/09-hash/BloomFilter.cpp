/**
 * 大样本量的黑名单系统
 * 1. 样本只能加入黑名单，但是不能从黑名单中移除
 * 2. 有一定量的失误率，但是失误率足够低：在黑名单中的数据，一定能判定出来；但是不是在黑名单中的数据，有可能会被判定在
 *
 * 设计k个哈希函数，每个数据在通过的时候，对k个函数都做一次哈希，得到结果[h1%m, h2%m, ..., hm%m],然后和在M中将这k个位置描黑
 */


#include <iostream>
#include <bitset>

using namespace std;

class BloomFilter {
private:

public:
};

int main() {
  bitset<128> ()
}