/*
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (40.25%)
 * Total Accepted:    29.9K
 * Total Submissions: 74.3K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 * 
 * Example 1:
 * 
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * 
 * 
 * 
 * Note:
 * 
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 * 
 * 
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        int val=0;
        for(int i=0;i<nums.size();i++)
        {
            mp[sum]++;
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end())
            {
                val+=mp[sum-k];
            }
        }
        return val;
    }
};
