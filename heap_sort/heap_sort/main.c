#include <stdio.h>
#include <stdlib.h>

/*
      9         15        15
     /         /          /
    15   =>   15    =>   13
    /         /          /
   13        13         13

   below condition is not possible, since supposed all childs of 9 had already been built

         9
        /
       13
      /
     15
*/

void sink(int* a, int i, int n) {
  
   int current = a[i];
   int  child = 2 * i + 1;
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

void build_max_heap(int *a, int n)
{
    int i; ;
    for (i = (n-2)/2; i>=0; i--){
      sink(a, i, n);
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
        sink(a, i, n);
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
