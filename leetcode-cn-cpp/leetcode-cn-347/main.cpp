#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    static bool myCmp(const pair<int,int> &a, const pair<int,int> &b){
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int ,int> m;
        for (auto v : nums){
            if (m.find(v) == m.end()){
                m[v] = 1;
            }else{
                m[v] = m[v]+1;
            }
        }
        vector<pair<int, int> > v;
        for (auto p: m){
            v.push_back(make_pair(p.first, p.second));
        }
        sort(v.begin(), v.end(), Solution::myCmp);
        vector<int> re;
        if (nums.size() == 0 || k<=0)
            return re;
        int count = 0;
        vector<pair<int, int> >::iterator it = v.begin();
        while(count<k){
            re.push_back(it->first);
            it++;
            count++;
        }

        return re;
    }
};

int main()
{
    vector<int> v = {1,1,1,2,2,3};
    Solution s;
    vector<int> re = s.topKFrequent(v, 3);
    for (auto v : re){
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}
