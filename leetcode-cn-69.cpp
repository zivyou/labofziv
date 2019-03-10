#include <iostream>

using namespace std;

class Solution {
public:

    int mySqrt(int x) {
        if (x == 0)
            return 0;
        const double myMin = 0.0000000001;
        double Xn2=2.1; double Xn=2.0;
        while (true){
            cout<<"Xn="<<Xn<<endl;
            double t = Xn2;
            Xn2 = Xn - (Xn*Xn - x)*1.0/(2.0*Xn);
            Xn = t;
            if (int(Xn2) == int(Xn))
                break;
            if (Xn2 >= Xn && Xn2 - Xn < myMin)
                break;
            if (Xn2 <= Xn && Xn - Xn2 < myMin)
                break;
        }
        return Xn;
    }
};

int main(){
    Solution s;
    cout<<s.mySqrt(1380590378)<<endl;
}