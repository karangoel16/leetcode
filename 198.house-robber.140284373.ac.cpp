/*
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (39.87%)
 * Total Accepted:    186.3K
 * Total Submissions: 467.3K
 * Testcase Example:  '[]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases. Also thanks to @ts for adding additional test cases.
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int curMax=0,preMax=0;
        for(auto i:nums){
            int temp=preMax;
            preMax=max(preMax,curMax);
            curMax=temp+i;
        }
        return std::max(preMax,curMax);
    }
};
