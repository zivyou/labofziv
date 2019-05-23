#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> data;
    map<string, vector<int> > m;

    void create(vector<string>& words) {
        data = words;
        for (int i=0; i<data.size(); i++){
            string w = data[i];
            if (m.find(w) == m.end()){
                m[w] = vector<int>(1, i);
            }else {
                vector<int> v = m[w];
                v.push_back(i);
                m[w] = v;
            }
        }
    }

    int abs(int a){
        return a>=0 ? a : -a;
    }
    
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int re = INT_MAX;
        create(words);
        if (word1.compare(word2)){
            vector<int> v1 = m[word1];
            vector<int> v2 = m[word2];
            for (int i=0; i<v1.size(); i++){
                for (int j=0; j<v2.size(); j++){
                    if (abs(v1[i]-v2[j]) < re)
                        re = abs(v1[i]-v2[j]);
                }
            }
            return re;
        }else{
            vector<int> v = m[word1];
            sort(v.begin(), v.end());
            int re = INT_MAX;
            for (int i=0; i<v.size()-1; i++){
                if ((v[i+1] - v[i]) < re){
                    re = v[i+1] - v[i];
                }
            }

            return re;
        }
    }
};

int main(){

    return 0;
}