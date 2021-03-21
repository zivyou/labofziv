#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:

    bool similar(string a, string b){
        if (a.length() != b.length()) return false;
        int count=0;
        for (int i=0; i<a.length(); i++){
            if (a[i] != b[i])
                count++;
            if (count > 1)
                return false;
        }
        if (count == 1)
            return true;
        else
            return false;

    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord)
            return 1;
        if (!wordList.size())
            return 0;
        queue<string> q;
        int path = 1;
        q.push(beginWord);
        int currentLevelCount = 1;
        int nextLevelCount = 0;
        while (!q.empty()){
            string s = q.front();
            q.pop();
            currentLevelCount--;
            printf("s=%s, path=%d\n", s.c_str(), path);

            for(int i=0; i<wordList.size(); i++){
                if (similar(wordList[i], s)){
                    if (wordList[i] == endWord)
                        return path+1;
                    q.push(wordList[i]);
                    wordList.erase(wordList.begin()+i);
                    i--;
                    nextLevelCount++;
                }
            }

            if (currentLevelCount == 0){
                path++;
                currentLevelCount = nextLevelCount;
                nextLevelCount = 0;
            }
        }

        return 0;
    }
};

int main()
{
    Solution s;
    vector<string> v({"hot","dot","dog","lot","log","cog"});
    //cout<<s.similar("hit", "hit")<<endl;
    cout << s.ladderLength("hit", "cog", v) << endl;
    return 0;
}
