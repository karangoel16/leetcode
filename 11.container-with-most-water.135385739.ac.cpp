/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (37.06%)
 * Total Accepted:    184.4K
 * Total Submissions: 497.5K
 * Testcase Example:  '[1,1]'
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int water=0;
        int i=0,j=height.size()-1;
        while(i<j)
        {
            int h=min(height[i],height[j]);
            water=max(water,(j-i)*h);//multiply with the minium
            if(i<j && height[i]<=h)i++;
            if(i<j && height[j]<=h)j--;
        }
        return water;
    }
};
