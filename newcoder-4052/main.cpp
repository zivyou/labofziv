#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int c1, c2;
    cin>>c1>>c2;
    int clocks = c2-c1;
    int hour, min, sec;
    hour = clocks/100/3600;
    min = (clocks - hour*3600*100)/100/60;
    int tmp = (clocks - hour*3600*100 - min*60*100);
    sec = tmp/100;
    if (tmp%100) {
        if (tmp % 100 >= 50)
        sec = sec + 1;
    }

    if (sec > 60){
        sec = sec - 60;
        min = min+1;
    }

    if (min > 60){
        min = min - 60;
        hour = hour + 1;
    }
    printf("%02d:%02d:%02d\n", hour, min, sec);

    return 0;
}