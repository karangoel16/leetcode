/*
 * [718] Maximum Length of Repeated Subarray
 *
 * https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (41.00%)
 * Total Accepted:    10.8K
 * Total Submissions: 26.4K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * Given two integer arrays A and B, return the maximum length of an subarray
 * that appears in both arrays.
 * 
 * Example 1:
 * 
 * Input:
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * Output: 3
 * Explanation: 
 * The repeated subarray with maximum length is [3, 2, 1].
 * 
 * 
 * 
 * Note:
 * 
 * 1 
 * 0 
 * 
 * 
 */
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m=A.size();
        int n=B.size();
        if(m==0 || n==0) return 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int res=0;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                if(A[i-1]==B[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    res=max(res,dp[i][j]);
                }
        return res;
    }
};
