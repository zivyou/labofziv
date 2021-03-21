#include <iostream>
using namespace std;

int cal(unsigned int *a, int N, unsigned int p){
    int *max = NULL;
    try {
        max = new int[N];
    }catch (bad_alloc &e){
        cout<<e.what()<<endl;
        return -1;
    }
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
       delete[] max;
    return true_max;
}

int main() {
    int N, i;
    i = 0;
    unsigned  int *a = NULL;
    try {
        a = new unsigned int[i];
    }catch (bad_alloc &memExp){
        cout<<memExp.what()<<endl;
        return -1;
    }
    unsigned int p;
    cin >> N>>p;
    while (i < N){
        cin>>a[i];
        i++;
    }

    std::cout << cal(a, N, p) << std::endl;
    cout<<"1"<<endl;
    //delete[] a;
    return 0;
}