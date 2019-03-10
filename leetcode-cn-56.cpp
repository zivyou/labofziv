#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
class Solution {
public:
    static bool cmp(Interval& a, Interval& b){
        if (a.start < b.start)
            return true;
        else
            return false;
    }

    vector<Interval>& rawMerge(vector<Interval>& intervals, Interval data){
        if (intervals.size() <= 0){
            intervals.push_back(data);
            return intervals;
        }

        Interval tail = intervals[intervals.size()-1];
        intervals.pop_back();
        if ( data.start <= tail.end){
            if (data.end > tail.end){
                intervals.push_back(Interval(tail.start, data.end));
                return intervals;
            }else{
                intervals.push_back(Interval(tail.start, tail.end));
                return intervals;
            }
        }else{
            intervals.push_back(tail);
            intervals.push_back(data);
            return intervals;
        }
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), Solution::cmp);
        vector<Interval> re;
        for (int i=0; i<intervals.size(); i++){
            re = rawMerge(re, intervals[i]);
        }

        return re;
    }
};

int main(){
    return 0;
}
