/*
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (37.31%)
 * Total Accepted:    49.3K
 * Total Submissions: 132.1K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 * 
 * 
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 * 
 * 
 * Example 1:
 * 
 * nums = [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 * 
 * 
 * Return 4
 * 
 * The longest increasing path is [1, 2, 6, 9].
 * 
 * 
 * Example 2:
 * 
 * nums = [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ]
 * 
 * 
 * 
 * 
 * Return 4
 * 
 * The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not
 * allowed.
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
    vector<vector<int>> cache,mat;
    vector<int> x_mov;
    vector<int> y_mov;
    int row,col;
public:
    Solution()
    {
        x_mov=vector<int>{-1,1,0,0};
        y_mov=vector<int>{0,0,-1,1};
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(!matrix.size() || !matrix[0].size())
            return 0;
        row=matrix.size();
        col=matrix[0].size();
        mat=matrix;
        int len=0;
        cache=vector<vector<int>>(row,vector<int> (col,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                len=max(len,helper(i,j,INT_MAX));
            }
        }
        return len;
    }
    int helper(int x,int y,int pre)
    {
        if(x<0 || y<0 || x>=row || y>=col || mat[x][y]>=pre)
            return 0;
        if(cache[x][y])
            return cache[x][y];
        int min=INT_MIN;
        for(int i=0;i<4;i++)
        {
            int temp_x=x+x_mov[i];
            int temp_y=y+y_mov[i];
            min=std::max(min,helper(temp_x,temp_y,mat[x][y]));
        }
        cache[x][y]=++min;
        return min;
    }
};
