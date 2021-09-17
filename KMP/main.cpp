#include <iostream>
#include <string.h>

using namespace std;

/**
 * 获取next数组
 * next[i]代表：当前位置的i，之前已经最长匹配了多长
 * [a,b,c,k,a,b,c] => [-1, 0, 0, 0, 0, 1, 2]
 * [a] => -1; [a, b] => 0, [a, b, c] => 0, [a, b, c, k] => 0; [a, b, c, k, a] => 0; [a, b, c, k, a, b]=>1;...
 * 同时，这个值隐含这另一层含义：因为[[..p1][...p2]x]形式中的p1和p2两部分相等，如果新出现的x匹配不上，意味着p1和p2是匹配上的，而p1和p2
 * 相等，我们就可不用户移动p1这么长了，可以直接跳到p2的开头继续比较就行了。
 * @param str
 * @param next
 * @return
 */
int get_next(char *str, int *next){
    int len = strlen(str);
    int j, k;
    next[0] = -1;
    k = -1;
    j = 0;
    while (j < len-1){
        if (k==-1 || str[j]==str[k]){
            k++;
            j++;
            next[j] = k;
        }else
            k = next[k];
    }

    return 0;
}


int KMPSearch(char *str1, char *str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int *next = new int[len2];
    get_next(str2, next);
    int i, j;
    i = j = 0;
    while (i < len1 && j < len2){
        if (j == -1 || str1[i]==str2[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    delete[] next;
    if (j==len2)
        return i - j;
    else
        return -1;
}


int main()
{
    char a[] = "hello world!";
    char b[] = "world";
    char c[] = "amckabc";
    int next[7];
    get_next(c, next);
    for (auto i:next) {
      cout<<i<<" ";
    }
    cout<<endl;
    int n = KMPSearch(a, b);
    cout<<n<<endl;
    return 0;
}
