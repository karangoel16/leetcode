/*
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (55.26%)
 * Total Accepted:    280.1K
 * Total Submissions: 506.8K
 * Testcase Example:  '[1]'
 *
 * Given an array of integers, every element appears twice except for one. Find
 * that single one.
 * 
 * 
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            res^=nums[i];
        }
        return res;
    }
};
