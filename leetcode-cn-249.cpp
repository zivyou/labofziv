#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    map<vector<int>, vector<string>> m;
    vector<int> hash(string s){
        vector<int> re;
        if (s.length() == 1){
            re.push_back(-1);
            return re;
        }

        for (int i=0; i<s.length()-1; i++){
            int gap = s[i+1] - s[i];
            if (gap < 0)
                gap += 26;
            re.push_back(gap);
        }
        return re;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
       
       for (int i=0; i<strings.size(); i++){
            vector<int> key = hash(strings[i]);
            if (m.find(key) == m.end()){
                vector<string> value;
                value.push_back(strings[i]);
                m[key] = value;
            }else{
                m[key].push_back(strings[i]);
            }
       }

       vector<vector<string>> re;
       for (auto pair : m){
           vector<string> v;
           re.push_back(pair.second);
       } 

       return re;
    }
};

int main(){

    return 0;
}