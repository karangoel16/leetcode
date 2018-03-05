/*
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (30.25%)
 * Total Accepted:    103.8K
 * Total Submissions: 343K
 * Testcase Example:  '[]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
        vector<vector<int>> dp(3,vector<int>(prices.size(),0));
        for(int i=1;i<=2;i++){
            int maxdiff=-prices[0];
            for(int j=1;j<prices.size();j++){
                dp[i][j]=max(dp[i][j-1],prices[j]+maxdiff);
                maxdiff = max(maxdiff,dp[i-1][j]-prices[j]);
            }
        }
        return dp[2][prices.size()-1];
    }
};
