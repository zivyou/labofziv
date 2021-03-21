#include <iostream>
using namespace std;

int main() {

    int cnt[10] = {0};
    char str[1001];
    int i = 0;
    cin>>str;
    for (i = 0; str[i]; i++){
        cnt[str[i]-'0']++;
    }
    i = 0;
    for (i=0;i<10;i++)
        if (cnt[i])
            cout<<i<<":"<<cnt[i]<<endl;
    return 0;
}