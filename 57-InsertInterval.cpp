/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    
    bool static compare(const Interval& a, const Interval& b){
        return a.start < b.start;
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        vector<Interval> result;
        sort(intervals.begin(), intervals.end(), Solution::compare);
        Interval tmpend = intervals[0];
        //tmpend.start = intervals[0].start;
        for(int i=0; i<intervals.size()-1; ++i){
            if(tmpend.end >= intervals[i+1].start){
                tmpend.end = max(tmpend.end, intervals[i+1].end);
            }
            else{
                result.push_back(tmpend);
                tmpend = intervals[i+1];
            }
        }
        result.push_back(tmpend);
        return result;
        
    }
};
