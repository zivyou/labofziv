#include <iostream>
using namespace std;

int main() {
    int N, i=0;
    cin>>N;
    int list[10005] = {0};
    int index, num;

    while (i<N){
        cin>>index>>num;
        list[index-1] += num;
        i++;
    }
    int max = list[0]; int max_index = 0;
    i = 0;
    while (i<10005){
        if (list[i]!=0) {
            if (list[i] > max) {
                max_index = i;
                max = list[i];
            }
        }
        i++;
    }
    cout<<max_index+1<<" "<<max<<endl;

    return 0;
}