
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    bool equal(double x, double y){
        if (abs(x-y)<std::numeric_limits<double>::epsilon()){
            return true;
        }else
            return false;
    }

    int setCache=0;
    vector<double> cache;
    
    double myPow(double x, int n) {
        if (isinf(x)){
            return std::numeric_limits<double>::infinity();
        }

        if (equal(x, 0.0))
            return 0.0;
        if (n == 0)
            return 1.0;
        if (equal(x, 1.0))
            return 1.0;
        if (equal(x, -1.0)){
            if (n > 0){
                if (n % 2 == 0)
                    return 1.0;
                else
                    return -1.0;
            }else{
                if (-n % 2 == 0)
                    return 1.0;
                else
                    return -1.0;
            }
        }
        if (n == INT_MAX){
            if (abs(x) > 1.0)
                return std::numeric_limits<double>::infinity();
            else
                return 0.0;
        }
        if (n == INT_MIN){
            if (abs(x) > 1.0)
                return 0.0;
            else
                return std::numeric_limits<double>::infinity();
        }

        if (!setCache){
            int k=sqrt(abs(n));
            //cout<<"===============================k="<<k<<endl;
            int i=1;
            double t = x;
            while (i<=k && i<=256){
                cache.push_back(t);
                cout<<"cache["<<i-1<<"]="<<t<<endl;
                t = t*x;
                i++;
            }
            setCache = 1;
        }
        if ((n>0?n:-n) <= cache.size()){ 
            if (n > 0)
                return cache[n-1];
            else
                return 1.0/cache[(-n)-1];
           
        }
        if (n<0){
            if (n==-1)
                return 1.0/x;
            if (n==-2)
                return 1.0/(x*x);
            if (!((-n)%2))
                return myPow(x, n/2)*myPow(x, n/2);
            else
                return myPow(x, n/2)*myPow(x, n/2)*1.0/x;
        }else if(n == 0)
            return 1.0;
        else{
            if (n==1)
                return x;
            if (n==2)
                return (x*x);
            if (!(n%2))
                return myPow(x, n/2)*myPow(x, n/2);
            else
                return myPow(x, n/2)*myPow(x, n/2)*x;
        }
    }
};

int main(){
    Solution s;
    cout<<s.myPow(-0.00001, -2147483648)<<endl;
}