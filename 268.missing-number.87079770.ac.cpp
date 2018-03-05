/*
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (44.86%)
 * Total Accepted:    159.4K
 * Total Submissions: 355.4K
 * Testcase Example:  '[3,0,1]'
 *
 * 
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * 
 * Example 1
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * 
 * Example 2
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * 
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int k=0;
        for(int i=1;i<=nums.size();++i)
        {
            k=k^i^nums[i-1];
        }
        return k;
    }
};
