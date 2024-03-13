#include <cstdio>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    string _(string word) {
        if (word.length() <= 2)
            for (int i=0; i<word.length(); i++) {
                word[i]=tolower(word[i]);
            }
        else {
            word[0] = toupper(word[0]);
            for (int i=1; i<word.length(); i++) {
                word[i]=tolower(word[i]);
            }
        }
        return word;
    }
    vector<string> split(string& title) {
        vector<string> result;
        int i=0; int j=0;
        while (i<title.length() && j<title.length()) {
            if (title[j]==' ') {
                if (j>i) result.push_back(_(title.substr(i, j-i)));
                i=j+1;
                j=i;
                continue;
            }
            j++;
        }
        if (j>i) result.push_back(_(title.substr(i, j-i)));
        return result;
    }
public:
    string capitalizeTitle(string title) {
        auto results = split(title);
        stringstream ss;
        for (int i=0; i<results.size(); i++) {
            ss<<results[i];
            if (i+1<results.size()) ss<<" ";
        }
        return ss.str();
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    auto r = s.capitalizeTitle("capiTalIze tHe titLe");
    printf("%s\n", r.c_str());
}
