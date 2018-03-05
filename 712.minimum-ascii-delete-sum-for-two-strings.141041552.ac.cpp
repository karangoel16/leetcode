/*
 * [712] Minimum ASCII Delete Sum for Two Strings
 *
 * https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
 *
 * algorithms
 * Medium (51.14%)
 * Total Accepted:    6.1K
 * Total Submissions: 12K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * Given two strings s1, s2, find the lowest ASCII sum of deleted characters to
 * make two strings equal.
 * 
 * Example 1:
 * 
 * Input: s1 = "sea", s2 = "eat"
 * Output: 231
 * Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to
 * the sum.
 * Deleting "t" from "eat" adds 116 to the sum.
 * At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum
 * possible to achieve this.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: s1 = "delete", s2 = "leet"
 * Output: 403
 * Explanation: Deleting "dee" from "delete" to turn the string into "let",
 * adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e]
 * to the sum.
 * At the end, both strings are equal to "let", and the answer is
 * 100+101+101+101 = 403.
 * If instead we turned both strings into "lee" or "eet", we would get answers
 * of 433 or 417, which are higher.
 * 
 * 
 * 
 * Note:
 * 0 < s1.length, s2.length .
 * All elements of each string will have an ASCII value in [97, 122]. 
 * 
 */

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int row=s1.length();
        if(!row)
            return 0;
        int col=s2.length();
        vector<vector<int>> dp(row+1,vector<int>(col+1,0));
        for (int j = 1; j <= col; j++)
            dp[0][j] = dp[0][j-1]+s2[j-1];
        for(int i=1;i<=row;i++){
            dp[i][0] = dp[i-1][0]+s1[i-1];
            for(int j=1;j<=col;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i][j-1]+s2[j-1],dp[i-1][j]+s1[i-1]);
            }
        }
        return dp[row][col];
    }
};
