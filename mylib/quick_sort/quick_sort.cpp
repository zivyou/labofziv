#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

int partition2(int *a, int l, int r){
    int i = l;
    int j = l;
    int s = a[r];
    while (j < r){
        if (a[j] >= s){
            swap(a[j], a[i]);
            i++;
        }
        j++;
    }
    swap(a[i], a[r]);
    return i;
}

int partition(int *a, int l, int r){
    int i = l-1;
    int j = l;
    int s = a[r];
    while (j < r){
        if (a[j] >= s){
            i++;
            swap(a[j], a[i]);
        }
        j++;
    }
    swap(a[i+1], a[r]);
    return i+1;
}

void sort(int *a, int l, int r){
    if (l >= r)
        return;
    int mid = partition2(a, l, r);
    sort(a, 0, mid-1);
    sort(a, mid+1, r);
}

int main(){
    int a[] = {1,2,3,4};
    for (auto num : a){
        cout<<num<<", ";
    }
    cout<<endl;

    sort(a, 0, sizeof(a)/sizeof(int)-1);
    for (auto num : a){
        cout<<num<<", ";
    }
}
