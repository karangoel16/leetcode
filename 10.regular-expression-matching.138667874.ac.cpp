/*
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (24.34%)
 * Total Accepted:    186.2K
 * Total Submissions: 765K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Implement regular expression matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 * 
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty() )
        {
            return s.empty();
        }
        vector<vector<bool>> dp(s.length()+1,vector<bool>(p.length()+1,false));
        dp[0][0]=true;
        for(int i=0;i<=s.length();i++)
        {
            for(int j=1;j<=p.length();j++)
            {
                if(p[j-1]=='*')
                {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                }
                else
                {
                    dp[i][j]=i>0 && dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');
                //dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};
