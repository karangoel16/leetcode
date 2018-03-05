/*
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (25.82%)
 * Total Accepted:    125.8K
 * Total Submissions: 487.1K
 * Testcase Example:  '[1,2,0]'
 *
 * 
 * Given an unsorted integer array, find the first missing positive integer.
 * 
 * 
 * 
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 * 
 * 
 * 
 * Your algorithm should run in O(n) time and uses constant space.
 * 
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 1;
        }
        std::sort(nums.begin(),nums.end());
        int i=0;
        int flag=1;
        while(i<nums.size())
        {
            while(nums[i]<=0 || nums[i]==nums[i+1])
                ++i;
            if(nums[i]!=flag)
            {
                return flag;
            }
            ++flag;
            ++i;
        }
        return flag;
    }
};
