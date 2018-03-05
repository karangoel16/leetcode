/*
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (26.13%)
 * Total Accepted:    110.8K
 * Total Submissions: 424K
 * Testcase Example:  '[0]'
 *
 * 
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * 
 * Each element in the array represents your maximum jump length at that
 * position. 
 * 
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * 
 * 
 * For example:
 * Given array A = [2,3,1,1,4]
 * 
 * 
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from
 * index 0 to 1, then 3 steps to the last index.)
 * 
 * 
 * 
 * Note:
 * You can assume that you can always reach the last index.
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<2)
            return 0;
        int level=0;
        int curMax=0;
        int i=0;
        while(curMax-i+1>0) //this is to check the level, just like sliding window
        {
            int max=curMax;
            level++;
            for(;i<nums.size() && i<=curMax;i++){
                max=std::max(max,nums[i]+i);
                if(max>=nums.size()-1)
                    return level;
            }
            curMax=max;
        }
        return 0;
    }
};
