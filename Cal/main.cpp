#include <iostream>
#include <cmath>
using namespace std;

/*
double cal(int x, int y, int z){
    int m = 2*x*y*z;
    double p = x*y*z/(1000*1.0);
    return (1040-m)*p - m*(1-p);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int x, y, z;
    double max=-999999999.0;
    int maxX, maxY, maxZ;
    for (x=1; x<=10; x++)
        for (y=1; y<=10; y++)
            for (z=1; z<=10; z++){
                double t = cal(x, y, z);
                if (t > max){
                    maxX = x; maxY = y; maxZ = z;
                    max = t;
                }
            }

    cout<<maxX<<" "<<maxY<<" "<<maxZ<<" "<<max<<endl;
    return 0;
}
 */

double P[7][34][17] = {-2.0};

int equal(double a, double b){
    if (a - b < 0.0000001 && a - b > 0)
        return 1;
    if (b -a < 0.0000001 && b-a > 0)
        return 1;
    return 0;
}

int CN[34][34] = {0};

int C(int x, int y){
    if (CN[x][y])
        return CN[x][y];

    int i = 1;
    int fenzi = 1;
    int ty = y;
    for (i=1; i<=x; i++){
        fenzi = fenzi*ty;
        ty = ty - 1;
    }
    int fenmu = 1;
    for (; x>=1; x--)
        fenmu = fenmu*x;
    CN[x][y] = fenzi/fenmu;
    return CN[x][y];
}

double p(int i, int x, int y){
    if (P[i][x][y] > 0)
        return P[i][x][y];
    double t = 0.0;
    if (i == 1){
        t = y/16.0 + y/16.0*x/(C(x, 33)*1.0) + y/16.0*(C(2,x)/(C(x, 33)*1.0));

    }
    if (i == 2){
        t = y/16.0*(C(3, x)/(C(x, 33)*1.0)) + (16-y)/16.0*(C(5, x)/(C(x, 33)*1.0));
    }
    if (i == 3){
        t = y/16.0*(C(4, x)/(C(x, 33)*1.0)) + (16-y)/16.0*(C(5, x)/(C(x, 33)*1.0));
    }
    if (i == 4){
        t = y/16.0*(C(5,x)/(C(x, 33)*1.0));
    }
    if (i == 5){
        t = (C(6, x))/ (C(x, 33)*1.0);
    }
    if (i == 6){
        t = y/16.0*(C(5,x))/(C(x, 33)*1.0);
    }
    P[i][x][y] = t;
    return t;
}

int main(){
    int ri, rx, ry; double re;
    int i, x, y;
    double max = -9999999999;
    int val[] = {0, 5, 10, 200, 3000, 1000000000, 100000000};
    double e = 0.0;
    for (x = 6; x<=33; x++){
        for (y = 1; y<=16; y++){
            e = 0.0;
            for (i = 1; i<=6; i++){
                e = e+((val[i]-y*C(6,x))*p(i, x, y) - y*C(6,x)*(1-p(i, x, y)));
            }
            if (e > max){
                max = e;
                ri = i; rx = x; ry = y;
                re = e;
            }
        }
    }
    cout<<rx<<" "<<ry<<" "<<re<<endl;
    cout<<p(1, 15, 8)<<endl;
}