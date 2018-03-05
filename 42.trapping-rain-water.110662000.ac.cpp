/*
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (37.48%)
 * Total Accepted:    154.8K
 * Total Submissions: 413.1K
 * Testcase Example:  '[]'
 *
 * 
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after
 * raining. 
 * 
 * 
 * 
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 * 
 * 
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int size=height.size();
        if(!size)
        {
            return 0;
        }
        vector<int> right_max(size);
        vector<int> left_max(size);
        left_max[0]=height[0];
        for(int i=1;i<size;i++)
        {
            left_max[i]=max(height[i],left_max[i-1]);
        }
        right_max[size-1]=height[size-1];
        for(int i=size-2;i>=0;i--)
        {
            right_max[i]=max(height[i],right_max[i+1]);
        }
        int ans=0;
        for(int i=1;i<size-1;i++)
        {
            ans+=min(right_max[i],left_max[i])-height[i];
        }
        return ans;
    }
};
