/*
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (32.94%)
 * Total Accepted:    18.2K
 * Total Submissions: 55.1K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * Example 1: 
 * Input:
 * 
 * 0 0 0
 * 0 1 0
 * 0 0 0
 * 
 * Output:
 * 
 * 0 0 0
 * 0 1 0
 * 0 0 0
 * 
 * 
 * 
 * Example 2: 
 * Input:
 * 
 * 0 0 0
 * 0 1 0
 * 1 1 1
 * 
 * Output:
 * 
 * 0 0 0
 * 0 1 0
 * 1 2 1
 * 
 * 
 * 
 * Note:
 * 
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 * 
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(!matrix.size())
        {
            return matrix;
        }
        auto dp=vector<vector<int>>(matrix.size(),vector<int>(matrix[0].size(),INT_MAX-1));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(!matrix[i][j])
                {
                    dp[i][j]=0;
                    continue;
                }
                int top=i>0?dp[i-1][j]:(INT_MAX-1);
                int left=j>0?dp[i][j-1]:(INT_MAX-1);
                dp[i][j]=min(min(top,left)+1,dp[i][j]);
            }
        }
        for(int i=matrix.size()-1;i>=0;i--)
        {
            for(int j=matrix[0].size()-1;j>=0;j--)
            {
                int bottom=i<matrix.size()-1?dp[i+1][j]:(INT_MAX-1);
                int right=j<matrix[0].size()-1?dp[i][j+1]:(INT_MAX-1);
                dp[i][j]=min(min(bottom,right)+1,dp[i][j]);
            }
        }
        return dp;
    }
};
