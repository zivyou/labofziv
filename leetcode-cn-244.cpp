#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class WordDistance {
public:
    vector<string> data;
    map<string, vector<int> > m;

    WordDistance(vector<string>& words) {
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
    
    int shortest(string word1, string word2) {
        int re = INT_MAX;

        vector<int> v1 = m[word1];
        vector<int> v2 = m[word2];
        for (int i=0; i<v1.size(); i++){
            for (int j=0; j<v2.size(); j++){
                if (abs(v1[i]-v2[j]) < re)
                    re = abs(v1[i]-v2[j]);
            }
        }

        return re;
    }
};

int main(){

    return 0;
}