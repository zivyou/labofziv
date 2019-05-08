#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    bool compare(int a, int b, int c){
        long long aa = a;
        long long bb = b;
        long long cc = c;
        if (aa - bb <= cc && bb - aa <= cc)
            return true;
        return false;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, int> m;
        for (int i=0; i<nums.size(); i++){
            m[nums[i]] = i;
        }

        for (map<int, int>::iterator iter = m.begin(); iter!=m.end(); iter++){
            int j=1;
            while (next(iter, j) != m.end()){
                if (compare(iter->first, next(iter,j)->first, t) && j<=k)
                    return true;
                if (j > k || !(compare(iter->first, next(iter,j)->first, t)))
                    break;
                j++;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> v({3,2,1});
    cout<<s.containsNearbyAlmostDuplicate(v, 3, 0)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
