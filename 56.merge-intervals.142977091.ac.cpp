/*
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (31.77%)
 * Total Accepted:    184.6K
 * Total Submissions: 581.1K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * 
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 * 
 */
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
        if(!intervals.size())
            return {};
        std::sort(intervals.begin(),intervals.end(),[](const Interval &a,const Interval &b){
            return a.start < b.start;
        });
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(res.back().end < intervals[i].start)
                res.push_back(intervals[i]);
            else
                res.back().end = std::max(res.back().end,intervals[i].end);
        }
        return res;
    }
};
