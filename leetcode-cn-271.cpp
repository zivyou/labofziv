#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string re;
        stringstream ss;
        for (auto str : strs){
            for (auto c: str){
                ss<<hex<<int(c);
            }
            ss<<'$';
        }
        ss<<endl;
        ss>>re;
        return re;
    }

    vector<string> split(string s){
        int begin = 0;
        int end = 0;
        vector<string> re;
        while (end < s.length()){
            if (s[end]!= '$'){
                end++;
            }else{
                re.push_back(s.substr(begin, end-begin));
                begin = end+1;
                end++;
            }
        }
        return re;
    }
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> v = split(s);
        vector<string> re;
        for (auto str : v){
            string st;
            for (int i=0; i<str.length(); i+=2){
                int it = 0;
                if (str[i] >= '0' && str[i] <= '9')
                    it = str[i]-'0';
                else
                    it = str[i]-'a'+10;
                if (str[i+1] >= '0' && str[i+1] <= '9')
                    it = it*16 + str[i+1]-'0';
                else
                    it = it*16 + str[i+1] - 'a'+10;
                st = st + (char)it;
            }

            re.push_back(st);
        }

        return re;
    }
};


int main(){
    Codec c;
    vector<string> input = {"hello", "world"};
    string en = c.encode(input);
    cout<<en<<endl;
    vector<string> v  = c.decode(en);
    for (auto st : v){
        cout<<st<<" ";
    }
    cout<<endl;
    return 0;
}