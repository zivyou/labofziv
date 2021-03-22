#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:
    bool less_than(vector<int>& a, vector<int>& b) {
        return (a[0]+a[1]) < (b[0]+b[1]);
    }
    void pair_swap(vector<int> &a, vector<int>& b ) {
        vector<int> tmp = a;
        a = b;
        b = tmp;
    }
    void insert(vector<vector<int>>& results, vector<int>& a) {
        results.push_back(a);
        for (int i=results.size()-1; i>0; --i) {
            if (less_than(results[i], results[i-1])) {
                pair_swap(results[i-1], results[i]);
            }
        }
    }
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> results;

        for (int i=0; i<nums1.size(); ++i) {
            for (int j=0; j<=(k) && j<nums2.size(); ++j) {
                vector<int> pair = {nums1[i], nums2[j]};
                if (results.size() < k) {
                    insert(results, pair);
                    continue;
                }
                if (results.size() >= k) {
                    if (!less_than(pair, results[results.size()-1])) {
                        continue;
                    } else {
                        results.pop_back();
                        insert(results, pair);
                    }
                }
            }
        }

        return results;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {-10,-4,0,0,6};
    vector<int> nums2 = {3,5,6,7,8,100};
    vector<vector<int>> results = s.kSmallestPairs(nums1, nums2, 10);

    for (int i=0; i<results.size(); i++) {
            cout<<"!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
        for (int j=0; j<results[i].size(); j++) {
            cout<<results[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
/*
[-10,-4,0,0,6]
[3,5,6,7,8,100]
10
*/
