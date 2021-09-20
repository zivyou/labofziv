#include <iostream>
#include <string>
using namespace std;

/**
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 */

/**
 * 滑动窗口方法:
 * [X1, X2, ... , Xm-1]是现有的窗口，这意味着：X1, X2, ..., Xm-1各不相同；
 * 现在新来一个Xm，假如与[X1, X2, ... , Xm-1]中的某个元素Xt相同，则需要将[X1, X2, ... , Xt]都踢出，接下来的窗口变成
 * [Xt+1, Xt+2, ..., Xm]
 * 整个滑动过程中记录最大的长度
 */

class Solution2 {
private:
  int map[256] = { 0 };
public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() <= 1) return s.length();
    for (int i=0; i<256; i++) map[i] = 0;
    int begin = 0; int end = 0; int re = 0;
    for (int i=0; i<s.length(); i++) {
      end = i;
      if (map[s[i]] == 1) {
        // 弹出和当前值相同的那个元素之前的所有元素
        while (begin < end && s[begin] != s[end]) {
          map[s[begin]] = 0;
          begin++;
        }
        if (begin<end && s[begin] == s[end]) {
          map[s[begin]] = 0;
          begin++;
        }
      }
      map[s[i]] = 1;
      re = re > end - begin +1 ? re : end - begin + 1;
    }
    re = re > end - begin + 1 ? re : end - begin + 1;
    return re;
  }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int begin=0;
        int j=0;
        for (begin=0; begin<(int)(s.size()); begin++){
            for (j=begin+1; j<(int)s.size(); j++){
                if (s.substr(begin, j-begin).find_first_of(s[j]) != -1)
                    break;
            }
            if (j-begin > max)
                max = j-begin;
        }

        return max;
    }
};

int main() {
    Solution s;
    cout<<s.lengthOfLongestSubstring(" ")<<endl;
    return 0;
}