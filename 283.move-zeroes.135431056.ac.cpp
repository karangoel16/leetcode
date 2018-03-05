/*
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (51.37%)
 * Total Accepted:    266.5K
 * Total Submissions: 518.7K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * 
 * 
 * For example, given nums  = [0, 1, 0, 3, 12], after calling your function,
 * nums should be [1, 3, 12, 0, 0].
 * 
 * 
 * 
 * Note:
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==0)
        {
            return ;
        }
        int cur=0;
        int i=0;
        while(i<nums.size())
        {
            if(nums[i])
            {
                std::swap(nums[i],nums[cur++]);
            }
            i++;
        }
    }
};
