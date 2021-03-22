#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1, num2;
        int cnt1 = 0; int cnt2 = 0;
        vector<int> re;
        for (auto num : nums){
            if ((cnt1==0 || num==num1) && num!=num2){
                cnt1++;
                num1=num;
            }else if (cnt2 == 0 || num == num2){
                cnt2++;
                num2 = num;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        auto count1 = 0;
        auto count2 = 0;
        for (auto num : nums){
            if (num == num1)
                count1++;
            if (num == num2)
                count2++;
        }

        if (count1 > nums.size()/3 )
            re.push_back(num1);
        if (num2 != num1){
            if (count2 > nums.size() / 3)
                re.push_back(num2);
        }
        return re;
    }
};

int main(){
    vector<int> data({3,2,3});
    Solution s;
    vector<int> re = s.majorityElement(data);
    for (auto num : re){
        cout<<num<<", ";
    }
    cout<<endl;
    return 0;
}