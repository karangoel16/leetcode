/*
 * [670] Maximum Swap
 *
 * https://leetcode.com/problems/maximum-swap/description/
 *
 * algorithms
 * Medium (38.52%)
 * Total Accepted:    18K
 * Total Submissions: 46.8K
 * Testcase Example:  '2736'
 *
 * 
 * Given a non-negative integer, you could swap two digits at most once to get
 * the maximum valued number. Return the maximum valued number you could get.
 * 
 * 
 * Example 1:
 * 
 * Input: 2736
 * Output: 7236
 * Explanation: Swap the number 2 and the number 7.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 9973
 * Output: 9973
 * Explanation: No swap.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The given number is in the range [0, 108]
 * 
 * 
 */
class Solution {
public:
    int maximumSwap(int num) {
        vector<int> dp(10,-1);
        string nums=to_string(num);
        for(int i=0;i<nums.size();i++)
            dp[nums[i]-'0']=i;
        for(int i=0;i<nums.size();i++)
            for(int k=9;k>(nums[i]-'0');k--)
                if(dp[k]>i){
                    std::swap(nums[i],nums[dp[k]]);
                    return stoi(nums);
                }
        return num;
    }
};
