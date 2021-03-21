#include <iostream>
#include <iomanip>
using namespace std;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void echo(int *a, int n){
    int i;
    for (i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void sort(int *a, int *b, int n){
    int i = 0;
    int j = 0;
    for (i=0; i<n; i++)
        for (j=0; j<n-i-1; j++){
            if (a[j]/(b[j]*1.0) < a[j+1]/(b[j+1]*1.0)){
                swap(&a[j], &a[j+1]);
                swap(&b[j], &b[j+1]);
            }
        }
}



int main() {
    int N;
    int amount;
    cin>>N>>amount;
    int *weights = new int[N];
    int *values = new int[N];
    int i = 0;
    while (i<N){
        cin>>weights[i];
        i++;
    }
    i = 0;
    while (i<N) {
        cin >> values[i];
        i++;
    }


    sort(values, weights, N);
//    echo(weights, N);
//    echo(values, N);
    double re = 0.0;
    i = 0;
    for (i=0; i<N && amount>0; i++){
        if (weights[i] <= amount){
            re = re+values[i];
            amount = amount-weights[i];
        }else{
            re = re + values[i]/(weights[i]*1.0)*amount;
            amount = 0;
        }

    }

    delete[] weights;
    delete[] values;
    cout.setf(ios::fixed);
    std::cout << fixed<< setprecision(2)<<re << std::endl;
    return 0;
}