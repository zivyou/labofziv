#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> re;
        re.push_back(0);

        for (int i=0; i<n; i++){
            vector<int> newRe(re);
            for (int j=re.size()-1; j>=0; j--){
                newRe.push_back(re[j]| 1<<(i));
            }
            re.clear();
            re = newRe; 
        }
        return re;
    }
};



int main(){
    vector<int> re;
    Solution s;
    re = s.grayCode(3);
    for (int i=0; i<re.size(); i++)
        cout<<re[i]<<" ";
    cout<<endl;
}