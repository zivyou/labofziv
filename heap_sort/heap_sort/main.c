#include <stdio.h>
#include <stdlib.h>


void build_max_heap(int *a, int n)
{
    int i; int current;
    int child;
    for (i = (n-2)/2; i>=0; i--){
        current = a[i];
        child = 2 * i + 1;
        while (child < n){
            if (child < n-1 && a[child]<a[child+1])
                child += 1; /* we choose the bigger one of two childs */
            if (a[child] <= current)
                break;

            a[(child-1)/2] = a[child];
            child = child * 2 + 1; /*  */
        }
        a[(child-1)/2] = current;
    }
}

void heap_sort(int *a, int n)
{
    int i; int tmp;
    build_max_heap(a, n);

    for (i=n-1; i>=0; i--){
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        build_max_heap(a, i);
    }
}

int main()
{
    int n, a[100];
    int i = 0;
    scanf("%d", &n);
    while (i < n){
        scanf("%d", &a[i]);
        i++;
    }

    heap_sort(a, n);

    i = 0;
    while (i < n){
        printf("%d ", a[i]);
        i++;
    }
    printf("\n");
    return 0;
}
