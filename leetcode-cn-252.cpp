#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool cross(vector<int> &a, vector<int> &b){
        if (a[1] > b[0])
            return true;

        return false;
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return true;
        sort(intervals.begin(), intervals.end());
        for (int i=0; i<intervals.size()-1; i++){
            if (cross(intervals[i], intervals[i+1]))
                return false;
        }

        return true;
    }
};

int main(){
    vector<vector<int> > intervals = {{7,10},{2,4}};
    Solution s;
    cout<<s.canAttendMeetings(intervals)<<endl;
    return 0;
}