/*
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (34.57%)
 * Total Accepted:    72.1K
 * Total Submissions: 208.5K
 * Testcase Example:  '[]'
 *
 * Note: This is an extension of House Robber.
 * 
 * After robbing those houses on that street, the thief has found himself a new
 * place for his thievery so that he will not get too much attention. This
 * time, all houses at this place are arranged in a circle. That means the
 * first house is the neighbor of the last one. Meanwhile, the security system
 * for these houses remain the same as for those in the previous street. 
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int MaxValue(vector<int> &nums,int low,int high){
        int preMax=0;
        int curMax=0;
        for(int i=low;i<high;i++){
            int temp=preMax;
            preMax=std::max(preMax,curMax);
            curMax=temp+nums[i];
        }
        return std::max(curMax,preMax);
    }
    int rob(vector<int>& nums) {
        int size=nums.size();
        if(!size)
            return 0;
        if(size==1)
            return nums[0];
        return std::max(MaxValue(nums,0,size-1),MaxValue(nums,1,size));
    }
};
