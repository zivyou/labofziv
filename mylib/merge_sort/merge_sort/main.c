#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int begin, int mid, int end)
{
    int *re = malloc(sizeof(int) * (end-begin+1));
    int i, j, k;
    i = 0;

    k = 0; i = begin; j = mid+1;


    while (i <= mid && j <= end){
        if (a[i] < a[j]){
            re[k++] = a[i];
            i++;
        }else{
            re[k++] = a[j];
            j++;
        }
    }

    if (i == mid+1){
        while (j <= end){
            re[k++] = a[j++];
        }
    }else if (j == end+1){
        while (i <= mid){
            re[k++] = a[i++];
        }
    }

    j = 0;
    for (i = begin; i <= end; i++){
        a[i] = re[j++];
    }
    free(re);
}

void merge_sort(int *a, int begin, int end)
{
    if (end == begin)   return;

    if ((end - begin) == 1){
        int tmp; int tmp2;
        tmp = a[begin] > a[end] ? a[begin] : a[end];
        tmp2 = a[begin] + a[end] - tmp;
        a[begin] = tmp2;
        a[end] = tmp;
        return ;
    }

    int mid = (begin + end) / 2;
    merge_sort(a, begin, mid);
    merge_sort(a, mid+1, end);
    merge(a, begin, mid, end);
}

int main()
{
    int n;
    int a[100];

    scanf("%d", &n);

    int i = 0;

    while (i < n){
        scanf("%d", &a[i]);
        i++;
    }

    merge_sort(a, 0, n-1);
    i = 0;
    while (i < n){
        printf("%d ", a[i]);
        i++;
    }
    printf("\n");
    return 0;
}
