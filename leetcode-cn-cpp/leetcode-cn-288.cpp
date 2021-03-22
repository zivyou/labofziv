#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class ValidWordAbbr {
public:
    map<string, vector<string>> m;
    vector<string> words;
    string shortcut(string str){
        string shortCut = "";
        shortCut.push_back(str[0]);
        if (str.length() > 2)
            shortCut = shortCut+std::to_string(str.length()-2);
        if (str.length() >= 2)
        shortCut.push_back(str[str.length()-1]);
        return shortCut;
    }
    ValidWordAbbr(vector<string>& dictionary) {
        words = dictionary;
        for (auto str : dictionary){
            string shortCut = shortcut(str);
            if (m.find(shortCut) == m.end()){
                vector<string> v;
                v.push_back(str);
                m[shortCut] = v;
            }else{
                m[shortCut].push_back(str);
            }
        }
    }
    
    bool isUnique(string word) {
        string shortCut = shortcut(word);
        if (m.find(shortCut) != m.end()){
            for (auto str : m[shortCut]){
                if (str.compare(word))
                    return false;
            }
        }

        return true;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */

int main(){
    vector<string> v = { "deer", "door", "cake", "card", "id" };

    ValidWordAbbr s(v);
    for (auto pair : s.m){
        cout<<pair.first<<"->"<<endl;
    }
    cout<<s.isUnique("make")<<endl;
    return 0;
}