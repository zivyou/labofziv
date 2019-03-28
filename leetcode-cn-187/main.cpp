#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int hash(string s){
        int num = 0;
        for (int i=0; i<s.length(); i++){
            num = num << 2;
            if (s[i] == 'A'){
                num = num | 0;
            }else if(s[i] == 'C'){
                num = num | 1;
            }else if (s[i] == 'G'){
                num = num | 2;
            }else if (s[i] == 'T'){
                num = num | 3;
            }else{
                cout<<"unexcepted char"<<endl;
            }
        }
        return num;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> re;
        map<int, int> nums;
        for (int i=0; i+9<s.length(); i++){
            string substr = s.substr(i, 10);
            int val = hash(substr);
            //cout<<"substr="<<substr<<", val="<<val<<endl;
            if (nums.find(val) == nums.end()){
                nums.insert(pair<int, int>(val, 1));
            }else{
                int time = nums.find(val)->second;
                if (time == 1){
                    re.push_back(substr);
                }
                nums.find(val)->second++;
            }
        }
        return re;
    }
};

int main()
{
    vector<string > re;

    Solution s;
    re = s.findRepeatedDnaSequences("AAAAAAAAAAAAAAAAAAAAAAAA");
    for (int i=0; i<re.size(); i++)
        cout<<re[i]<<"; ";
    cout<<endl;
    return 0;
}
