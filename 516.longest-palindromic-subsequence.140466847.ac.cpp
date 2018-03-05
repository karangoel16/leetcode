/*
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (42.72%)
 * Total Accepted:    27.3K
 * Total Submissions: 63.9K
 * Testcase Example:  '"bbbab"'
 *
 * 
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000.
 * 
 * 
 * Example 1:
 * Input: 
 * 
 * "bbbab"
 * 
 * Output: 
 * 
 * 4
 * 
 * One possible longest palindromic subsequence is "bbbb".
 * 
 * 
 * Example 2:
 * Input:
 * 
 * "cbbd"
 * 
 * Output:
 * 
 * 2
 * 
 * One possible longest palindromic subsequence is "bb".
 * 
 */
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
        for(int i=0;i<s.length();i++){
            dp[i][i]=1;
            for(int j=i-1;j>=0;j--){
                if(s[i]==s[j])
                    dp[i][j]=max(dp[i][j],dp[i-1][j+1]+2);
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j+1]);
            }
        }
        return dp[s.length()-1][0];
    }
};
