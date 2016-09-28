#include <stdio.h>
#include <stdlib.h>

/*
* replace all blank in a sentence into '%02'
*/
void replace_blank(char *s)
{
    int count = 0;
    int len = strlen(s);
    int i;

    for (i = 0; s[i]; i++){
        if (s[i] == ' ') count++;
    }

    int j = len -1;
    len = len + count * 2;
    s[len] = 0;
    i = len -1;

    for (; j >= 0; j--){
        if (s[j] != ' ') {
            s[i] = s[j];
            i--;
        }
        else{
            s[i] = '2';
            s[i-1] = '0';
            s[i-2] = '%';
            i = i - 3;
        }

        if (i == j ) break;
    }

}

int main()
{
    char str[1000];
    gets(str);

    replace_blank(str);
    printf("%s\n", str);
    return 0;
}
