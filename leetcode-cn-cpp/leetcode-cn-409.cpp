#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
private:
    vector<int> m;
public:
    int longestPalindrome(string s) {
        vector<int> m(128, 0);
        for (char c : s) {
            m[c-'A']++;
        }
        vector<int> n;
        for (auto x : m) if (x > 0) n.push_back(x);
        std::sort(n.begin(), n.end(), [](int a, int b) { return a > b; });

        int result = 0; bool no_odd = false;
        for (int i : n) {
            if (i > 0 && i%2 == 0) result += i;
            if (i > 0 && i%2 != 0 && no_odd == false) {
                result += i;
                no_odd = true;
                continue;
            }
            if (i > 0 && i%2 != 0 && no_odd == true) {
                result += i-1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    printf("%d\n", solution.longestPalindrome(s));
    return 0;
}