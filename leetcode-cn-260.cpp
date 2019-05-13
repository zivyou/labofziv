#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, bool> m;
        vector<int> re;
        for (auto num: nums){
            if (m.find(num) == m.end()){
                m.insert(pair<int, bool>(num, true));
            }else{
                m.erase(num);
            }
        }

        map<int, bool>::iterator it = m.begin();
        while (it != m.end()){
            re.push_back(it->first);
            it++;
        }

        return re;
    }
};

int main(){
    Solution s;
    vector<int> v({1,2,1,3,2,5});
    vector<int> re = s.singleNumber(v);
    for (auto num : re){
        cout<<num<<", ";
    }
    cout<<endl;
    return 0;
}