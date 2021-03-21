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

    int minMeetingRooms(vector<vector<int> >& intervals) {
        if (intervals.size() <= 1)
            return 1;
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > data;
        data.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); i++){
            bool found = false;
            for (int j=0; j<data.size(); j++){
                if (!cross(data[j], intervals[i])){
                    data[j] = intervals[i];
                    found = true;
                    break;
                }
            }

            if (!found){
                data.push_back(intervals[i]);
            }
        }

        return data.size();
    }
};

int main(){
    return 0;
}