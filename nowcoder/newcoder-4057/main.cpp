#include <iostream>
using namespace std;

int main() {
    const int weight[] = {7, 9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    const char M[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int N, i=0;
    int normal = 1;
    cin>>N;
    while (i<N){
        char input[19];
        cin>>input;
        int j = 0;
        unsigned int sum = 0;

        for (j=0; j<17; j++){
            sum = sum + (input[j]-'0')*weight[j];
        }

        if (input[17] != M[sum%11]) {
            cout << input << endl;
            normal = 0;
        }
        i++;
    }
    if (normal)
        std::cout << "All passed" << std::endl;
    return 0;
}