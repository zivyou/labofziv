#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
/*
"33030230130210"
"33030302301210"
*/
class Solution {
public:

    static int cmp(int a, int b){
        string s1; string s2;
        stringstream ss;
        ss<<a<<b; ss>>s1;
        ss.clear();
        ss<<b<<a; ss>>s2;
        for (int i=0; i<s1.length(); i++){
            if (s1[i] > s2[i])
                return 1;
            if (s1[i] < s2[i])
                return 0;
        }

        return 0;
    }


    /*
     static int cmp(int a, int b){

        stringstream ss;
        int re1; int re2;
        ss<<a<<b; ss>>re1;
        ss.clear();
        ss<<b<<a; ss>>re2;
        if (re1 > re2)
            return 1;
        else
            return 0;
        return 0;
    }*/
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), Solution::cmp);
        stringstream ss;
        string re;
        int begin = false;
        for (int i=0; i<nums.size(); i++){
            if (!begin && nums[i] != 0)
                begin = true;
            if (begin)
                ss<<nums[i];
        }
        ss>>re;
        if (!re.length())
            re = "0";
        return re;
    }

};

int main()
{
    Solution s;
    vector<int> v({30,302});
    cout<<s.largestNumber(v)<<endl;
    return 0;
}
