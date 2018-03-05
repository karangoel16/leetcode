/*
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Easy (51.71%)
 * Total Accepted:    21.1K
 * Total Submissions: 40.8K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.)  You
 * may assume all four edges of the grid are surrounded by water.
 * 
 * Find the maximum area of an island in the given 2D array.
 * (If there is no island, the maximum area is 0.)
 * 
 * Example 1:
 * 
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * 
 * Given the above grid, return 6.
 * 
 * Note the answer is not 11, because the island must be connected
 * 4-directionally.
 * 
 * 
 * Example 2:
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 * 
 * 
 * Note:
 * The length of each dimension in the given grid does not exceed 50.
 * 
 */
class Solution {
    vector<vector<int>> grid;
    int row;
    int col;
    vector<int> x_mov{1,-1,0,0};
    vector<int> y_mov{0,0,-1,1};
public:
    bool check(int i,int j)
    {
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j]==INT_MAX || grid[i][j]==0)
        {
            return false;
        }
        return true;
    }
    int helper(int i,int j)
    {
        int pos=0;
        if(check(i,j))
        {
            grid[i][j]=INT_MAX;
            pos++;
            for(int k=0;k<4;k++)
            {
                int x_temp=i+x_mov[k];
                int y_temp=j+y_mov[k];
                pos+=helper(x_temp,y_temp);
            }
        }
        return pos;
    }
    int maxAreaOfIsland(vector<vector<int>>& g) {
        grid=g;
        row=grid.size();
        if(!row)
        {
            return 0;
        }
        col=grid[0].size();
        int maxVal=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                maxVal=max(maxVal,helper(i,j));   
            }
        }
        return maxVal;
    }
};
