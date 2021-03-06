/*
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (42.58%)
 * Total Accepted:    180.9K
 * Total Submissions: 424.8K
 * Testcase Example:  '1\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * 
 * 
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 * 
 * 
 * Note: m and n will be at most 100.
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++)
            dp[0][i]=1;
        for(int i=1;i<=m;i++){
            dp[i][0]=1;
            for(int j=1;j<=n;j++)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
        return dp[m-1][n-1];
    }
};
