#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(char *str, int begin, int end)
{
    int mid;
    int i = 0;

    if ((begin + end)%2 == 1 ){
        mid = (begin + end) / 2;
        for (i = begin; i <= mid; i++){
            swap(&str[i], &str[end - (i-begin)]);
        }
    } //3 4 5 6

    if ((begin + end)%2 == 0 ){
        mid = (begin + end) / 2;
        for (i = begin; i < mid; i++){
            swap(&str[i], &str[end - (i-begin)]);
        }
    } //3 4 5 6  7

}

int main()
{
    char str[1000];
    int i = 0;
    int begin = 0;
    int end;

    gets(str);
    reverse(str, 0, strlen(str)-1);
    while (i < strlen(str)){
        if (str[i] == ' '){
            end = i - 1;
            reverse(str, begin, end);
            begin = i + 1;
        }
        i++;
    }

    reverse(str, begin, strlen(str)-1);

    printf("%s\n", str);
    return 0;
}
