//最近写的东西脑子抽风，运行时间疯狂爆炸

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
    vector<Interval> merge(vector<Interval>& intervals) {
        list<Interval>::iterator it, st;
        list<Interval> lint;
        for(int i=0; i<intervals.size(); ++i)
            lint.push_back(intervals[i]);
        for(it = lint.begin(); it!=lint.end(); ++it){
            for(st = lint.begin(); st != lint.end(); ){
                if(it == st){ ++st; continue;} 
                if((it->start >= st->start && it->start <= st->end) || (it->end >= st->start && it->end <= st->end)){
                    it->start = min(st->start, it->start);
                    it->end = max(st->end, it->end);
                    st = lint.erase(st);
                    continue;
                }
                ++st;
            }
        }
        vector<Interval> result;
        for(it=lint.begin(); it!=lint.end(); ++it)
            result.push_back(*it);
        if(result.size() != intervals.size())
            return merge(result);
        return result;
    }
   
};

//补充一个O(n)时间内完成的算法
class Solution {
public:

	bool static  compare(const Interval& a, const Interval& b) {
		return (a.start < b.start);
	}
	vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() < 2) return intervals;
		//intervals.push_back(newInterval);
		vector<Interval> result;
		sort(intervals.begin(), intervals.end(), Solution::compare);
		Interval tmpend = intervals[0];
		//tmpend.start = intervals[0].start;
		for (int i = 0; i<intervals.size() - 1; ++i) {
			if (tmpend.end >= intervals[i + 1].start) {
				tmpend.end = max(tmpend.end, intervals[i + 1].end);
			}
			else {
				result.push_back(tmpend);
				tmpend = intervals[i + 1];
			}
		}
		result.push_back(tmpend);
		return result;

	}
};

