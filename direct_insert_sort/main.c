#include <stdio.h>
#include <stdlib.h>


void direct_insert_sort(int *a, int n)
{
    int i = 1;
    int pos;
    int ai;

    while (i < n){
        ai = a[i];

        pos = i-1;
        while (pos >= 0){
            if (ai < a[pos]){
                a[pos+1] = a[pos];
                pos--;
            }else
                break;

        }

        a[pos+1] = ai;
        i++;
    }
}

int main()
{
    int n;
    int a[1000], i;

    scanf("%d", &n);
    i = 0;
    while (i < n){
        scanf("%d", &a[i]);
        i++;
    }

    direct_insert_sort(a, n);

    i = 0;
    while (i < n){
        printf("%d ", a[i]);
        i++;
    }
    printf("\n");
    return 0;
}
