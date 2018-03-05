/*
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (28.85%)
 * Total Accepted:    120.6K
 * Total Submissions: 418.2K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * 
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 * 
 * 
 * 
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as
 * [1,2],[3,10],[12,16].
 * 
 * 
 * 
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        auto it=intervals.begin();
        for(;it!=intervals.end();it++)
        {
            if((*it).start > newInterval.end)
            {
                break;
            }
            else if((*it).end<newInterval.start)
            {
                ret.push_back(*it);
            }
            else
            {
                newInterval.start= min(newInterval.start,(*it).start);
                newInterval.end=max(newInterval.end,(*it).end);
            }
        }
        ret.push_back(newInterval);
        for(; it!=intervals.end(); ++it)
		    ret.push_back(*it);
        return ret;
    }
};
