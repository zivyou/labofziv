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

    Interval rawCombine(Interval &a, Interval &b){
        Interval re;
        re.start = a.start > b.start ? b.start : a.start;
        re.end = a.end > b.end ? a.end : b.end;

        return re;
    }

    bool canCombine(Interval &a, Interval &b){
        // assume a.start <= b.start
        if (a.end >= b.start)
            return true;
        return false;
    }

    int compare(Interval &a, Interval &b){
        return a.start - b.start;
    }

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i;
        for ( i=intervals.size()-1; i>=0; i--){
            if (compare(newInterval, intervals[i]) > 0){
                intervals.insert(intervals.begin()+i+1, newInterval);
                break;
            }
        }
        if (i < 0)
            intervals.insert(intervals.begin(), newInterval);
        vector<Interval> result;
        result.push_back(intervals[0]);
        for ( i=0; i<intervals.size(); i++){
            Interval t = result[result.size()-1];
            if (canCombine(t, intervals[i])){
                result.pop_back();
                result.push_back(rawCombine(t, intervals[i]));
            }
        }

        return result;
    }
};

int main(){

}