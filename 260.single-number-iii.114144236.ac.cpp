/*
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (52.94%)
 * Total Accepted:    79K
 * Total Submissions: 149.2K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * 
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 * 
 * 
 * For example:
 * 
 * 
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 * 
 * 
 * Note:
 * 
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 * 
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(),nums.end(),0,bit_xor<int>());
        diff&=-diff;
        vector<int> rets={0,0};
        for(auto num:nums)
        {
            if((num&diff)==0)
            {
                rets[0]^=num;
            }
            else
            {
                rets[1]^=num;
            }
        }
        return rets;
    }
};
