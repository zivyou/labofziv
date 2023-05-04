#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class Solution {
private:
    std::unordered_map<int, std::list<int>> db;
public:
    Solution(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            int n = nums.at(i);
            if (db.find(n) == db.end()) {
                std::list<int>* index = new std::list<int>();
                index->push_back(i);
                db[n] = *index;
            } else {
                std::list<int>& index = db[n];
                index.push_back(i);
            }
        }
    }

    int pick(int target) {
        if (db.find(target) == db.end()) return -1;
        std::list<int>& index = db[target];
        auto iter = db[target].begin();
        unsigned int count = index.size();
        long at = ::random() % count;
//        ::cout<<"at: "<<at<<", count:"<<count<<::endl;
        for (int i = 0; i<at; i++) {
            iter++;
        }
        return *iter;
    }
};

int main() {
    Solution s(*new vector<int>{1, 2, 3, 3, 3});
    int i = 0;
    while (i ++ < 10)
    ::cout<<s.pick(3)<<::endl;
    return 0;
}