/*
 * [583] Delete Operation for Two Strings
 *
 * https://leetcode.com/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (44.50%)
 * Total Accepted:    15.1K
 * Total Submissions: 34K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 
 * Given two words word1 and word2, find the minimum number of steps required
 * to make word1 and word2 the same, where in each step you can delete one
 * character in either string.
 * 
 * 
 * Example 1:
 * 
 * Input: "sea", "eat"
 * Output: 2
 * Explanation: You need one step to make "sea" to "ea" and another step to
 * make "eat" to "ea".
 * 
 * 
 * 
 * Note:
 * 
 * The length of given words won't exceed 500.
 * Characters in given words can only be lower-case letters.
 * 
 * 
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        if(!n)
            return m;
        auto dp=vector<vector<int>>(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                dp[i][j]=max(dp[i-1][j-1]+(word1[i-1]==word2[j-1]),max(dp[i-1][j],dp[i][j-1]));
        return m+n-2*dp[n][m];
    }
};
