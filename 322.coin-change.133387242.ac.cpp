/*
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (26.62%)
 * Total Accepted:    87K
 * Total Submissions: 327K
 * Testcase Example:  '[1]\n0'
 *
 * 
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * 
 * 
 * Example 1:
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 * 
 * 
 * 
 * Example 2:
 * coins = [2], amount = 3
 * return -1.
 * 
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0 || !amount)
        {
            return 0;
        }
        vector<vector<long>> dp(coins.size()+1,vector<long>(amount+1,INT_MAX));
        for(int i=0;i<=coins.size();i++)
        {
            dp[i][0]=0;
        }
        std::sort(coins.begin(),coins.end());
        for(long i=1;i<=coins.size();i++)
        {
            for(long j=1;j<=amount;j++)
            {
                //std::cout<<coins[i-1]<<"*";
                if(j>=coins[i-1])
                    dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
                else
                    dp[i][j]=dp[i-1][j];
                //std::cout<<dp[i][j]<<"\t";
            }
            //std::cout<<endl;
        }
        return dp[coins.size()][amount]!=INT_MAX?dp[coins.size()][amount]:-1;
    }
};
