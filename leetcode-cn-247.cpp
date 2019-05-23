#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> list = {0, 1, 6, 8, 9};
    bool compared(char a, char b){
        if (a == b){
            if (a == '0' || a=='8' || a=='1')
                return true;
        }
        if (a == '6' && b == '9')
            return true;
        if (a == '9' && b == '6')
            return true;
        
        return false;
    }
    bool isStrobogrammatic(string num) {
        int i=0; int j=num.length()-1;
        while (i<=j){
            if (!compared(num[i], num[j]))
                return false;
            i++; j--;
        }

        if (num.length() > 1){
            if (num[0] == '0')
                return false;
        }
        return true;
    }
    void dfs(vector<string>& re, int n, string tmpRe){
        if (tmpRe.length() >= n ){
            if (isStrobogrammatic(tmpRe)){
                re.push_back(tmpRe);
            }
            return;
        }

        int mid;
        if (n % 2){
            mid = n/2;
            if (tmpRe.length() > mid){
                int i=0;
                while (mid + i < tmpRe.length()){
                    if (!compared(tmpRe[mid+i], tmpRe[mid-i]))
                        return;
                    i++;
                }
            }
        }else{
            mid = (n-1)/2;
            int left = mid;
            int right = mid+1;
            while (left >= 0 && right < tmpRe.length()){
                if (!compared(tmpRe[left], tmpRe[right]))
                    return;
                left--; right++;
            }

        }
        

        for (int i=0; i<list.size(); i++){
            tmpRe += ('0'+list[i]);
            dfs(re, n, tmpRe);
            tmpRe.pop_back();
        }
    }

    vector<string> findStrobogrammatic(int n) {
        vector<string> re;
        string tmpRe = "";
        dfs(re, n, tmpRe);
        return re;
    }
};




int main(){
    return 0;
}