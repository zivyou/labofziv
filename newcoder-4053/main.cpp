#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N; char c;
    cin>>N>>c;
    int i = int(int(sqrt((N+1)/(2.0)))-1);
    //cout<<"i="<<i<<endl;
    int level = 2*i+1;
    int cnt = 0;
    int j = level;
    while (j > 0){
        int k=0;
        for (k=0; k<(level-j)/2;k++)
            cout<<' ';
        for (k=1; k<=j; k++) {
            cout << c;
            cnt++;
        }
        /*
        for (k=0; k<(level-j)/2;k++)
            cout<<' ';
            */
        cout<<endl;
        j -= 2;
    }

    j = 3;
    while (j <= level){
        int k = 1;
        for (k=0; k<(level-j)/2;k++)
            cout<<' ';
        for (k=1; k<=j; k++) {
            cout << c;
            cnt ++;
        }
        /*
        for (k=0; k<(level-j)/2;k++)
            cout<<' ';
            */
        cout<<endl;
        j += 2;
    }
    cout<<N-cnt<<endl;
    return 0;
}