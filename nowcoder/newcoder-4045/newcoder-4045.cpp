//https://www.nowcoder.com/pat/6/problem/4045
#include <iostream>
#include <string.h>

using namespace std;

void swap(char *a, char *b){
	char t = *a;
	*a = *b;
	*b = t;
}

void max_sort(char *max){
	int i = 0, j=0;
	for (i=0; i<4; i++)
		for (j=0; j<4-i-1; j++)
			if (max[j] < max[j+1])
				swap(&max[j], &max[j+1]);
}

void min_sort(char *max){
	int i = 0, j=0;
	for (i=0; i<4; i++)
		for (j=0; j<4-i-1; j++)
			if (max[j] > max[j+1])
				swap(&max[j], &max[j+1]);
}

void sort(char *input, char *max, char *min){

	memset(max, 0, 5);
	memset(min, 0, 5);


    strncpy(max, input, 5);
	strncpy(min, input, 4);

	max_sort(max);
	min_sort(min);

}

void sub(char *max, char *min, char *re){
	// 6123 - 4234 = 1889
	int i = 3;
	int jiewei[5] = {0};
    char maxt[5], mint[5];
    strncpy(maxt, max, 5);
    strncpy(mint, min, 5);

	for (i = 3;i >= 0; i--){
		if (jiewei[i+1] == 1)
			maxt[i] = (char) (maxt[i] - 1);
		if (maxt[i] < mint[i]){
			jiewei[i] = 1;
			re[i] = (char) (maxt[i]-mint[i]+10+'0');
		}else
			re[i] = (char)(maxt[i] - mint[i]+'0');
	}
}


int main(){
	char input[5];
	char max[5];
	char min[5];
	char re[5];
	//sub((char *)"6123", (char *)"4234", re);

        cin.getline(input, 5);
        input[4] = 0;

        int len = strlen(input);
        if (len < 4){
            int i;
            for (i=3; len&&input[len-1]; i--) {
                input[i] = input[len - 1];
                len--;
            }
            int j = 0;
            for (j=0; j<=i;j++)
                input[j]='0';
        }

        strncpy(re, input, 5);
        do {
            sort(re, max, min);
            sub(max, min, re);
            cout << max << " - " << min << " = " << re << endl;
            if (re[0] == re[1] && re[1] == re[2] && re[2] == re[3]) {
                //cout << "N - N = 0000" << endl;
                return 0;
            }
        } while (strcmp(re, "6174") != 0);

	return 0;
}
