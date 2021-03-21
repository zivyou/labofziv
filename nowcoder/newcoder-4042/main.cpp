/*https://www.nowcoder.com/pat/6/problem/4042*/
#include <iostream>

using namespace std;

int main()
{
    char A[11];
    char B[11];
    int DA, DB;
    cin>>A>>DA>>B>>DB;
    int i = 0;
    int PA , PB;
    PA = PB = 0;
    while (A[i]){
        if (A[i] == (DA+'0')){
            PA = PA * 10 + DA;
        }
        i++;
    }
    i = 0;
    while (B[i]){
        if (B[i] == (DB + '0')){
            PB = PB * 10 + DB;
        }
        i++;
    }
    cout << PA+PB << endl;
    return 0;
}
