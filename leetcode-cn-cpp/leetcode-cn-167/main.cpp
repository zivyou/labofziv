#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> re;
        if (numbers.size() <= 1)
            return re;

        int i=0; int j=numbers.size()-1;
        while (i < j){
            if (numbers[i]+numbers[j] < target)
                i++;
            else if (numbers[i] + numbers[j] > target)
                j--;
            else{
                re.push_back(i);
                re.push_back(j);
                return re;
            }
        }

        return re;
    }
};

int main()
{
    Solution s;
    vector<int> v({});
    vector<int> re;
    re = s.twoSum(v, 0);
    return 0;
}
