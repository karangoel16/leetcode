/*
 * [452] Minimum Number of Arrows to Burst Balloons
 *
 * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
 *
 * algorithms
 * Medium (44.52%)
 * Total Accepted:    20.1K
 * Total Submissions: 45.2K
 * Testcase Example:  '[[10,16],[2,8],[1,6],[7,12]]'
 *
 * There are a number of spherical balloons spread in two-dimensional space.
 * For each balloon, provided input is the start and end coordinates of the
 * horizontal diameter. Since it's horizontal, y-coordinates don't matter and
 * hence the x-coordinates of start and end of the diameter suffice. Start is
 * always smaller than end. There will be at most 104 balloons.
 * 
 * An arrow can be shot up exactly vertically from different points along the
 * x-axis. A balloon with xstart and xend bursts by an arrow shot at x if
 * xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be
 * shot. An arrow once shot keeps travelling up infinitely. The problem is to
 * find the minimum number of arrows that must be shot to burst all balloons. 
 * 
 * Example:
 * 
 * Input:
 * [[10,16], [2,8], [1,6], [7,12]]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * One way is to shoot one arrow for example at x = 6 (bursting the balloons
 * [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two
 * balloons).
 * 
 * 
 */
struct compare
{
    bool operator()(pair<int,int> a,pair<int,int> b)
    {
        if(a.second<b.second)
        {
            return true;
        }
        if(a.second==b.second && a.first<b.first)
        {
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size()==0)
        {
            return 0;
        }
        std::sort(points.begin(),points.end(),compare());
        int count=1;
        int t=points[0].second;
        int i=0;
        while(i<points.size())
        {
            if(t<points[i].first || t>points[i].second)
            {
                t=points[i].second;
                count++;
            }
            i++;
        }
        return count;
    }
};
