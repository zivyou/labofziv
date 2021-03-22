#include <iostream>
#include <map>


using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        for (int i=0; i<nums.size(); i++){
            if (m.find(nums[i]) == m.end()){
                m[nums[i]] = i;
            }else
                return true;
        }

        return false;
    }

};

int main()
{

    cout << "Hello world!" << endl;
    return 0;
}
