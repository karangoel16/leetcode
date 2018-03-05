/*
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (31.97%)
 * Total Accepted:    110.3K
 * Total Submissions: 345K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * 
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 * 
 * 
 * click to show more practice.
 * 
 * More practice:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n).
 * 
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left=0;
        int sum=0;
        int min=INT_MAX;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(sum>=s)
            {
                min=std::min(min,right-left+1);
                sum-=nums[left++];
            }
        }
        return min==INT_MAX?0:min;
    }
};
