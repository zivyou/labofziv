#include <iostream>
#include <vector>
using namespace std;

/**
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/**
 * 双向遍历：一个从左，一个从右。但是得保证遍历过程确实能停下来并且时间复杂度要为O(n)
 * a[m],a[m+1], ..., a[n-1], a[n]
 * 如果 a[m]<=a[n], 那么i++;
 * 如果a[m]>a[n], j--;
 *
 * 证明：
 * 将这个逻辑翻译成数学命题：不失一般性的，我们考虑a[m]<=a[n]的情况（a[m]>a[n]的情况可以依葫芦画瓢）
 * 已知a[m]<=a[n]，证明：若min(a[n], a[m])*(n-m)<min(a[d1], a[d2])*(d2-d1)，则必有m<d1;
 * 证：
 * 首先[d1, d2]落在[m, n]中，因此有：m<=d1<d2<=n；故m<=d1。现在只需要证明m!=d1即可。下面用反证法证明。
 * 设m=d1，有：
 * min(a[m], a[n])*(n-m) < min(a[m], a[d2])*(d2-m)
 * 由于(n-m)>(d2-m),因此min(a[m], a[n])<min(a[m], a[d2])
 * 又由已知的a[m]<=a[n]，有：a[m]<min(a[m], a[d])，显然这是不可能的。
 * 所以我们反证法的假设是不对的，即m!=d1。也就有m<d1。
 * 换句话说，只要a[m]<=a[n]，假如说我们最终想求解的区间[d1, d2]落在[m, n]中，那我们可以确定d1>m，因此可以无脑i++
 *
 *
 */

class Solution {
public:
    int min(int a, int b){
        if (a > b)
            return b;
        else
            return a;
    }
    int maxArea(vector<int>& height) {
        int max = 0;
        int i=0;
        for (i=0; i<height.size()-1; i++){
            int j=0;
            for (j=i+1; j<height.size(); j++){
                if ((j-i)*min(height[i], height[j]) > max)
                    max = (j-i)*min(height[i], height[j]);
            }
        }

        return max;
    }
};
int main() {
    vector<int> v = {1,8};
    Solution s;
    cout<<s.maxArea(v)<<endl;
    return 0;
}