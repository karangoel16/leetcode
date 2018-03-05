/*
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (43.80%)
 * Total Accepted:    46.2K
 * Total Submissions: 105.5K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * ⁠
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.  
 * 
 * 
 * Example 1:
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array is positive and will not exceed 20. 
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int dp [nums.size()][2001];
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<2001;j++)
            {
                dp[i][j]=0;
            }
        }
        dp[0][1000+nums[0]]=1;
        dp[0][1000-nums[0]]+=1;
        for(int i=1;i<nums.size();i++)
        {
            for(int sum=-1000;sum<=1000;sum++)
            {
                if(dp[i-1][sum+1000]>0)
                {
                    dp[i][sum+1000+nums[i]]+=dp[i-1][1000+sum];
                    dp[i][sum+1000-nums[i]]+=dp[i-1][1000+sum];
                }
            }
        }
        return S>1000?0:dp[nums.size()-1][S+1000];
    }
};
