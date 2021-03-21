#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    vector<string> rawFindItinerary(map<string, vector<string>> m, string start, int n, vector<string> &re){
        if (n <= 0){
            return re;
        }

        if (m.find(start) == m.end()) return vector<string>();
        if (m[start].size() == 0) return vector<string>();

        for (int i=0; i<m[start].size(); i++){
            string strTmp = m[start][i];
            m[start].erase(m[start].begin()+i);
            re.push_back(strTmp);
            vector<string> v = rawFindItinerary(m, strTmp, n-1, re);
            if (v.size() > 0)
                return v;
            re.pop_back();
            m[start].insert(m[start].begin()+i, strTmp);

        }

        return vector<string>();
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        if (tickets.size() <= 0)
            return vector<string>();
        map<string, vector<string>> m;
        for (auto elem : tickets){
            string key = elem[0];
            if (m.find(key) != m.end()){   // attention please
                bool found = false;
                for (int i=0; i<m[key].size(); i++){
                    if (elem[1].compare(m[key][i]) < 0){
                        m[key].insert(m[key].begin()+i, elem[1]);
                        found = true;
                        break;
                    }
                }
                if (!found){
                    m[key].push_back(elem[1]);
                }
            }else{
                vector<string> v;
                v.push_back(elem[1]);
                m[key] = v;
            }
        }

        vector<string> re;
        re.push_back("JFK");
        return rawFindItinerary(m, "JFK", tickets.size(), re);
    }
};

int main()
{
    Solution s;
    vector<vector<string>> v = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<string> re = s.findItinerary(v);
    for (auto str : re){
        cout<<str<<" ";
    }
    cout<<endl;
    return 0;
}
