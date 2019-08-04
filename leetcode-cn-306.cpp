#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;


class Solution {
public:
    vector<long long> judge(string &nums, int i, int j, int k){
        long long a = stoll(nums.substr(0, i));
        long long b = stoll(nums.substr(i, j-i));
        long long c = stoll(nums.substr(j, k-j));
        
       //cout<<a<<", "<<b<<", "<<c<<endl;
        if (a+b == c){
            
            vector<long long> re;
            re.push_back(a);
            re.push_back(b);
            re.push_back(c);
            return re;
        }else
            return vector<long long>();
    }
    bool isAdditiveNumber(string num) {
        if (num.length() < 3)
            return false;
        vector<vector<long long> > tmp;
        for (int i=1; i<num.size()-1; i++){
            for (int j=i+1; j<num.size(); j++){
                for (int k=j+1; k<=num.size(); k++){
                    vector<long long> v = judge(num, i, j, k);
                    if (v.size() != 0){
                        tmp.push_back(v);
                    }
                }
            }
        }

        if (!tmp.size())
            return false;
        else{
            for (auto v : tmp){
                long long a = v[0];
                long long b = v[1];
                long long c = v[2];
                string  str = to_string(a)+to_string(b)+to_string(c);
                while (num.find_first_of(str) == 0){
                    if (str.length() >= num.length())
                        break;
                    a = b;
                    b = c;
                    c = a+b;
                    str = str+to_string(c);
                }
                if (!str.compare(num))
                    return true;
            }
        }

        return false;
    }
};



int main(){
    return 0;
}