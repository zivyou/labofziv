#include <cstdio>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> _(vector<string>& words, string& first, string& second) {
        if (words.size() < 3) return {};
        vector<string> result;
        for (int i=2; i<words.size(); i++) {
            if (words[i-2]==first && words[i-1]==second) {
                result.push_back(words[i]);
            }
        }
        return result;
    }
public:
    vector<string> findOcurrences(string text, string first, string second) {
        stringstream ss(text);
        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return _(words, first, second);
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    auto vec = s.findOcurrences("we will we will rock you", "we", "will");
    for (auto& w : vec) {
        printf("%s ", w.c_str());
    }
    printf("\n");
    return 0;
}
