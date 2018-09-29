#include <iostream>
#include <string.h>
using namespace std;

void swap(char *a, char *b){
    char t = *a;
    *a = *b;
    *b = t;
}

void sort(char * s){
    int len = (int)strlen(s);
    int i , j;
    for (i = 0; i<len;i++)
        for (j=0; j<len-i-1;j++)
            if (s[j] > s[j+1]){
                swap(&s[j], &s[j+1]);
            }
}

int main() {
    int cnt[10];
    char  input[51];
    char t;
    int i = 0;
    while (i<10){
        cin>>cnt[i];
        i++;
    }
    i=0;
    int j, k;
    for (i=0;i<10;i++){
        for (j = 0; j<cnt[i];j++){
            input[k++] = char(i+'0');
        }
    }
    input[k] = 0;
    sort(input);
    i = 0;
    if (input[0] == '0'){
        for (i=0; input[i]=='0'; i++);
        swap(&input[0], &input[i]);
    }
    std::cout << input << std::endl;
    return 0;
}