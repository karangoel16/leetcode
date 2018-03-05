/*
 * [525] Contiguous Array
 *
 * https://leetcode.com/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (41.49%)
 * Total Accepted:    22.2K
 * Total Submissions: 53.6K
 * Testcase Example:  '[0,1]'
 *
 * Given a binary array, find the maximum length of a contiguous subarray with
 * equal number of 0 and 1. 
 * 
 * 
 * Example 1:
 * 
 * Input: [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with equal number of
 * 0 and 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
 * number of 0 and 1.
 * 
 * 
 * 
 * Note:
 * The length of the given binary array will not exceed 50,000.
 * 
 */
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int size=nums.size();
        if(!size) return 0;
        mp[0]=-1;
        int sum=0;
        int mx=0;
        for(int i=0;i<size;i++){
            sum+=(nums[i]==0)?-1:1;
            if(mp.find(sum)!=mp.end())
                mx=std::max(mx,i-mp[sum]);
            else
                mp[sum]=i;
        }
        return mx;
    }
};
