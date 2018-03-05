/*
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (42.51%)
 * Total Accepted:    131.3K
 * Total Submissions: 309K
 * Testcase Example:  '[1]'
 *
 * 
 * Given an array of integers, every element appears three times except for
 * one, which appears exactly once. Find that single one.
 * 
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
        int ones=0;
        int two=0;
        int common;
        for(int i=0;i<nums.size();i++)
        {
            two=two|ones&(nums[i]);
            ones^=nums[i];
            //std::cout<<ones<<" "<<two<<" "<<nums[i]<<"\n";
            common=~(two&ones);
            two=two&common;//remove the common element between one and two
            ones=ones&common;
            
        }
        return ones;
    }
};
