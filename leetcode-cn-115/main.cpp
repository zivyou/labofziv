#include <iostream>
#include <string>
#include <queue>

using namespace std;
/*
class Solution {
public:
    void rawNumDistinc(int &re, string curPath, string s, string t){
        if (curPath.length()){
            if (curPath[0] != t[0])
                return;
        }
        if (curPath == t){
            re++;
            return;
        }
        if (curPath.length() + s.length() < t.length())
            return;
        if (s.length() <= 0)
            return;

        //cout<<"curPath="<<curPath<<endl;
        if (curPath.length() < t.length()){
            string rawS = s;
            s.erase(0, 1);
            if (t.find(curPath) == 0){
                rawNumDistinc(re, curPath, s, t);
            }
            if (t.find(curPath) == 0){
                rawNumDistinc(re, curPath.append(1, rawS[0]), s, t);
            }
        }
    }

    int numDistinct(string s, string t) {
        int re = 0;
        rawNumDistinc(re, "", s, t);
        return re;
    }
};
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();
        if (sLen < tLen)
            return 0;
        if (tLen == 0)
            return 1;



        unsigned int** dp = new unsigned int *[sLen+1];
        for (int i=0; i<=sLen; i++){
            dp[i] = new unsigned int[tLen+1];
            for (int j=0; j<=tLen; j++)
                dp[i][j]= 0;
        }

        for (int i=0; i<=sLen; i++){
                dp[i][0] = 1;
        }

        for (int i=1; i<=sLen; i++)
            for (int j=1; j<=tLen; j++){
                if (i < j)
                    continue;
                if (i == j){
                    dp[i][j] = (s.substr(0, i) == t.substr(0, j));
                }else{

                    if (s[i-1] == t[j-1]){
                        dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                    }else{
                        dp[i][j] = dp[i-1][j];
                    }
                }

            cout<<dp[i][j]<<endl;
            }

        return dp[sLen][tLen];
    }
};

int main()
{
    Solution s;
    cout<<s.numDistinct("xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo","rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys")<<endl;
    return 0;
}
