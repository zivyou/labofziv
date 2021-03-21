#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    int abs(int a){
        return a >= 0 ? a : -a;
    }
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int begin = -2*words.size(); int end = 2 * words.size();
        int min = INT_MAX;
        cout<<"word1="<<word1<<endl;
        for (int i=0; i<words.size(); i++){
            if (!words[i].compare(word1)){
                begin = i;
                if (abs(begin - end) < min){
                    //cout<<"1 begin="<<begin<<", end="<<end<<endl;
                    min = abs(begin - end);
                }
            }

            if (!words[i].compare(word2)){
                end = i;
                if (abs(begin - end) < min){
                    //cout<<"2 begin="<<begin<<", end="<<end<<endl;
                    min = abs(begin - end);
                }
            }
        }

        return min;
    }
};

int main(){
    vector<string> words({"practice", "makes", "perfect", "coding", "makes"});
    Solution s;
    cout<<s.shortestDistance(words, "makes", "practice")<<endl;
    return 0;
}