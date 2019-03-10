#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
    bool similar(string a, string b){
        //if (a.length() != b.length()) return false;
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

    vector<vector<string>> partial(string endWord, vector<string>& wordList, int &endWordAt){
        vector<vector<string>> re;
        for (int i=0; i<wordList.size(); i++){
            if (re.size() == 0){
                vector<string> v;
                v.push_back(wordList[i]);
                re.push_back(v);
                if (wordList[i] == endWord)
                    endWordAt = 0;
            }else{
                int found = 0;
                for (int j=0; j<re.size(); j++){
                    for (int k=0; k<re[j].size(); k++){
                        if (similar(re[j][k], wordList[i])){
                            found = 1;
                            re[j].push_back(wordList[i]);
                            if (wordList[i] == endWord)
                                endWordAt = j;
                            break;
                        }
                        if (found)
                            break;
                    }
                }
                if (!found){
                    vector<string> v;
                    v.push_back(wordList[i]);
                    re.push_back(v);
                    if (wordList[i] == endWord)
                        endWordAt = re.size()-1;
                }
            }
        }
        return re;
    }

    void rawFindLadders(vector<vector<string>> &re, vector<string> curPath, string endWord, vector<string> wordList, int &maxLength){
        if (wordList.size() <= 0)
            return;
        if (curPath.size() > maxLength)
            return;
        //cout<<"wordList.size()="<<wordList.size()<<endl;
        for (int i=0; i<wordList.size(); i++){
            if (similar(wordList[i], curPath[curPath.size()-1])){
                if (wordList[i] == endWord){
                    curPath.push_back(endWord);
                    if (curPath.size() > maxLength)
                        return;
                    else if (curPath.size() == maxLength)
                        re.push_back(curPath);
                    else{
                        re.clear();
                        re.push_back(curPath);
                        maxLength = curPath.size();
                    }
                    return;
                }else{
                    if (std::find(curPath.begin(), curPath.end(), wordList[i]) != curPath.end())
                        return;
                    vector<string> newPath = curPath;
                    newPath.push_back(wordList[i]);
                    vector<string> newWordList = wordList;
                    newWordList.erase(newWordList.begin()+i);
                    rawFindLadders(re, newPath, endWord, newWordList, maxLength);
                }
            }
        }
    }


    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList){
        vector<vector<string>> re;
        int endWordAt = 0;
        vector<vector<string>> partialList = partial(endWord, wordList, endWordAt);

        vector<string> path;
        path.push_back(beginWord);
        int maxLength = INT_MAX;
        rawFindLadders(re, path, endWord, partialList[endWordAt], maxLength);
        return re;
    }
};


int main()
{
    vector<vector<string>> re;
    Solution s;
    vector<string> wordList(
{"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"});
    re = s.findLadders("qa", "sq", wordList);

    for (int i=0; i<re.size(); i++){
        for (int j=0; j<re[i].size(); j++)
            cout<<re[i][j]<<", ";
        cout<<endl;
    }
    return 0;
}
