#include <cstdio>
#include <string>
#include <ctime>

using namespace std;

/*
class Solution {
private:
    int _(string& ss1, string& ss2) {
        string s1; string s2;
        if (ss1.length() > ss2.length()) {
            s1 = ss2;
            s2 = ss1;
        } else {
            s1 = ss1; s2 = ss2;
        }
        if (s1.rfind(s2, 0) == 0) return s2.length();
        if (s2.rfind(s1, 0) == 0) return s1.length();
        int max = 0;
        for (int i=0; i<s1.length(); i++) {
            char c = s1.at(i);
            int idx2 = s2.find_first_of(c);
            if (idx2 < 0) continue;
            auto ls1 = s1.substr(0, i);
            auto ls2 = s2.substr(0, idx2);
            int length1 = _(ls1, ls2); int length2;
            if (i<s1.length()-1 && idx2<s2.length()-1) {
                auto rs1 = s1.substr(i+1, s1.size()-i);
                auto rs2 = s2.substr(idx2+1, s2.length()-idx2);
                length2 = _(rs1, rs2);
            } else {
                length2 = 0;
            }
            if (length1+length2+1 > max) {
                max = length1+length2+1;
            }
        }
        return max;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return _(text1, text2);
    }
};
*/

class Solution {
private:
    int** dp;
    int _(string& s1, string& s2) {
        for (int i=0; i<s1.length(); i++) {
            for (int j=0; j<s2.length(); j++) {
                if (s1[i] == s2[j]) {
                    if (i>0 && j>0) {
                        dp[i][j] = dp[i-1][j-1]+1;
                    } else {
                        dp[i][j] = 1;
                    }
                } else {
                    if (i>0 && j>0) {
                        dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                        continue;
                    }
                    if (i == 0 && j>0) {
                        dp[i][j] = dp[i][j-1];
                        continue;
                    }
                    if (i>0 && j==0) {
                        dp[i][j] = dp[i-1][j];
                    }
                    if (i==0 && j==0) {
                        dp[i][j] = 0;
                    }
                }
            }
        }
        for (int i=0; i<s1.length(); i++) {
            for (int j=0; j<s2.length(); j++) {
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }
        return dp[s1.length()-1][s2.length()-1];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int x = text1.length(); int y = text2.length();
        dp = new int*[x];
        for (int i=0; i<x; i++) dp[i] = new int[y];
        int re = _(text1, text2);
        for (int i=0; i<x; i++) delete[] dp[i];
        return re;
    }
};

int main() {
    auto start = clock();
    Solution s;
    string s1 = "dknkdizqxkdczafixidorgfcnkrirmhmzqbcfuvojsxwraxe";
    string s2 = "dulixqfgvipenkfubgtyxujixspoxmhgvahqdmzmlyhajerqz";
    auto re = s.longestCommonSubsequence(s1, s2);
    auto end = clock();
    printf("====================== %d, %.5f\n", re, (end-start)*1.0/CLOCKS_PER_SEC);
}