#include <iostream>
using namespace std;
int main() {

    unsigned  int a, b, d;
    cin >> a >> b>>d;
    unsigned int raw_value = a+b;
    int re = 0;
    unsigned  int c = d;
    while (raw_value / c){
        c = c * d;
    }
    c = c/d;
    int i = 0;
    char str[101]={0};
    while (c>=d){
        str[i++] = char(raw_value/c + '0');
        raw_value = raw_value % c;
        c = c/d;
    }
    str[i] = char(re*10+raw_value + '0');
    cout<<str<<endl;
    return 0;
}