/*
 * [645] Set Mismatch
 *
 * https://leetcode.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (39.77%)
 * Total Accepted:    23.3K
 * Total Submissions: 58.6K
 * Testcase Example:  '[1,2,2,4]'
 *
 * 
 * The set S originally contains numbers from 1 to n. But unfortunately, due to
 * the data error, one of the numbers in the set got duplicated to another
 * number in the set, which results in repetition of one number and loss of
 * another number. 
 * 
 * 
 * 
 * Given an array nums representing the data status of this set after the
 * error. Your task is to firstly find the number occurs twice and then find
 * the number that is missing. Return them in the form of an array.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 * 
 * 
 * 
 * Note:
 * 
 * The given array size will in the range [2, 10000].
 * The given array's numbers won't have any order.
 * 
 * 
 */
class Solution {
    public:
    vector<int> findErrorNums(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++)
            x^=nums[i]^(i+1);
        x &= -x;
        int acc1=0,acc2=0;
        for (unsigned i = 0; i < nums.size(); ++i)
        {
            ((nums[i] & x) == 0) ? acc1 ^= nums[i] : acc2 ^= nums[i];
            (((i + 1) & x) == 0) ? acc1 ^= i + 1 : acc2 ^= i + 1;
        }
        for (auto n : nums)
            if (n == acc1)
                return {acc1, acc2};
        return {acc2,acc1};
    }
};