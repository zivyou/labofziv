/*https://www.nowcoder.com/pat/6/problem/4043*/
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char A[1001];
    int B;
    cin>>A>>B;
    int i = 0;
    int len = strlen(A);
    int b, s;
    b = A[i] - '0';
    while (A[i+1]){
        if (b < B){
            b = b*10+A[i+1]-'0';
            i++;
            continue;
        }else{
            s = b/B;
            cout<<s+'0';
            b = b%B;
            continue;
        }
    }
    b = b*10+A[i]-'0';
    s = b/B;
    b = b%B;
    cout<<s+'0'<<" "<<b<<endl;
    return 0;
}
