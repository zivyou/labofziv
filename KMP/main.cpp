#include <iostream>
#include <string.h>

using namespace std;

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


int KMPsearch(char *str1, char *str2){
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
    int n = KMPsearch(a, b);
    cout<<n<<endl;
    return 0;
}
