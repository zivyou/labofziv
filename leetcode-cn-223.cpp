#include <iostream>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int leftBottomX = (max<int>(A,E));
        int leftBottomY = max<int>(B, F);
        int rightTopX = (min<int>(C,G));
        int rightTopY = min<int>(D, H);

        long long crossArea = abs((rightTopX-leftBottomX) * (rightTopY - leftBottomY));
        if (E >= C || G <= A || F >= D || H <=  B)
            crossArea = 0;
        if (B>=H || D<=F || A>=G || C<=E)
            crossArea = 0;
        long long area1 = (C-A)*(D-B);
        long long area2 = (G-E)*(H-F);
        cout<<"area1="<<area1<<", area2="<<area2<<", crossArea="<<crossArea<<endl;
        return area1+area2-crossArea;
    }
};

int main(){
    Solution s;
    cout<<s.computeArea(1282,-1386,1290,-1380,1284,-1384,1296,-1375)<<endl;
    return 0;
}