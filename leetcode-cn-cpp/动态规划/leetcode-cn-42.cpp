#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> data;
    int cal(int l, int h){
        int height = data[l] < data[h] ? data[l] : data[h];
        int total = (h - l - 1) * height;
        for (int i=l+1; i<h; i++){
            if (data[i] <= height)
                total = total - data[i];
            else
                total = total - height;
        }
        return total;
    }
    int trap(vector<int>& height) {
        data = height;
        if (data.size() <= 2)
            return 0;
        int *t = new int[data.size()];
        for (int i=0; i<data.size(); i++)
            t[i] = 0;
        for (int i=1; i<data.size(); i++){
            if (data[i] <= data[i-1])
                t[i] = t[i-1];
            else{
                int l = -1;int max = -1;
                for (int j=i-1; j>=0; j--){
                    if (data[j] >= data[i]){
                        l = j;
                        break;
                    }else{
                        if (data[j] > max){
                            max = data[j];
                            l = j;
                        }
                    }
                }
                t[i] = t[l] + cal(l, i);
            }
        }
        return t[data.size()-1];
    }
};

int main(){
    int a[]={};
    vector<int> v(a, a+sizeof(a)/4);
    Solution s;
    cout<<s.trap(v)<<endl;
    return 0;
}