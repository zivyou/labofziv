#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cal(unsigned int *a, int N, unsigned int p){
    int *max = NULL;

    max = ( int *)malloc(N*sizeof( int));
    memset(max, 0, N);
    int i = N;
    int j=0;
    i=0;
    for (i=0; i<N; i++){
        max[i] = 0;
        int cnt = 0;
        for (j=0; j<N; j++){
            if (a[j] >= a[i]){
                if (a[j] <= a[i]*p)
                    cnt++;
            }
        }
        if (cnt > max[i])
            max[i] = cnt;
        cnt = 0;
        for (j=0; j<N; j++){
            if (a[j] <= a[i]){
                if (a[i] <= a[j]*p)
                    cnt++;
            }
        }

        if (cnt >= max[i])
            max[i] = cnt;
    }
    int true_max = -1;
    for (i = 0; i<N; i++)
        if (max[i] > true_max)
            true_max = max[i];
    if (max)
        free(max);
    return true_max;
}

int main() {
    int N, i;
    i = 0;
    unsigned  int *a = NULL;

    a = (unsigned int*)malloc(N * sizeof(unsigned int));
    memset(a, 0, N);
    unsigned int p;
    scanf("%d%d", &N, &p);
    while (i < N){
        scanf("%d", &a[i]);
        i++;
    }
    printf("%d\n", cal(a, N, p));
    free(a);
    return 0;
}