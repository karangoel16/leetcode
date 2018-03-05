/*
 * [115] Distinct Subsequences
 *
 * https://leetcode.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (32.14%)
 * Total Accepted:    80.7K
 * Total Submissions: 251.2K
 * Testcase Example:  '""\n"a"'
 *
 * 
 * Given a string S and a string T, count the number of distinct subsequences
 * of S which equals T.
 * 
 * 
 * 
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ACE" is a
 * subsequence of "ABCDE" while "AEC" is not).
 * 
 * 
 * 
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 * 
 * 
 * Return 3.
 * 
 */
class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.length();
        int n=t.length();
        if (n > m) return 0; 
        vector<vector<int>> dp (n+1,vector<int>(m+1,0));
        //std::cout<<"*";
        for(int i=0;i<m+1;i++)
        {
            dp[0][i]=1;//initializing vector for initial stage
        }
        //std::cout<<"^";
        //std::cout<<dp.size();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j] = dp[i][j-1] + (t[i-1]==s[j-1]? dp[i-1][j-1] : 0);
                //std::cout<<dp[i][j]<<"\t";
            }
            //std::cout<<endl;
        }
        return dp[n][m];
    }
};
