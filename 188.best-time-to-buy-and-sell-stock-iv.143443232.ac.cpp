/*
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (24.85%)
 * Total Accepted:    58.8K
 * Total Submissions: 236.5K
 * Testcase Example:  '2\n[]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most k
 * transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(!prices.size() || !k)
            return 0;
        if (k >= prices.size()) {
            return allTimeProfit(prices);
        }
        vector<int> prev(prices.size(),0);
        vector<int> curr(prices.size(),0);
        
        for(int i=1;i<=k;i++){
            int maxdiff=-prices[0];
            for(int j=1;j<prices.size();j++){
                curr[j]=max(curr[j-1],prices[j]+maxdiff);
                maxdiff = max(maxdiff,prev[j]-prices[j]);
            }
            std::swap(curr,prev);
        }
        return prev[prices.size()-1];
    }
    int allTimeProfit(vector<int> arr){
        int profit = 0;
        for(int i=1; i < arr.size();i++)
            profit+=max(arr[i]-arr[i-1],0);
        return profit;
    }
};
