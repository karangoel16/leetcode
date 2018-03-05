/*
 * [447] Number of Boomerangs
 *
 * https://leetcode.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Easy (46.41%)
 * Total Accepted:    33.7K
 * Total Submissions: 72.6K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is
 * a tuple of points (i, j, k) such that the distance between i and j equals
 * the distance between i and k (the order of the tuple matters).
 * 
 * Find the number of boomerangs. You may assume that n will be at most 500 and
 * coordinates of points are all in the range [-10000, 10000] (inclusive).
 * 
 * Example:
 * 
 * Input:
 * [[0,0],[1,0],[2,0]]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 * 
 * 
 */
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res=0;
        for(int i=0;i<points.size();++i)
        {
            unordered_map<long,int>mp;
            for(int j=0;j<points.size();++j)
            {
                if(i==j)
                {
                    continue;
                }
                int dx=points[i].first-points[j].first;
                int dy=points[i].second-points[j].second;
                int key =(dx*dx)+(dy*dy);
                ++mp[key];
            }
            for(auto i:mp)
            {
                if(i.second>1)
                {
                    res+=(i.second)*(i.second-1);
                }
            }
        }
        return res;
    }
};
