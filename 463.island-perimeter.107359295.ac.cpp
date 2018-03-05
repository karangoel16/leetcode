/*
 * [463] Island Perimeter
 *
 * https://leetcode.com/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (57.80%)
 * Total Accepted:    73K
 * Total Submissions: 126.2K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * You are given a map in form of a two-dimensional integer grid where 1
 * represents land and 0 represents water. Grid cells are connected
 * horizontally/vertically (not diagonally). The grid is completely surrounded
 * by water, and there is exactly one island (i.e., one or more connected land
 * cells). The island doesn't have "lakes" (water inside that isn't connected
 * to the water around the island). One cell is a square with side length 1.
 * The grid is rectangular, width and height don't exceed 100. Determine the
 * perimeter of the island.
 * 
 * Example:
 * 
 * [[0,1,0,0],
 * ⁠[1,1,1,0],
 * ⁠[0,1,0,0],
 * ⁠[1,1,0,0]]
 * 
 * Answer: 16
 * Explanation: The perimeter is the 16 yellow stripes in the image below:
 * 
 * 
 * 
 */
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;
        vector<int> x_next=vector<int>{-1,1,0,0};
        vector<int> y_next=vector<int>{0,0,-1,1};
        int row=grid.size();
        if(!row)
        {
            return 0;//if nothing exist
        }
        int col=grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j])//this means it is a land
                {
                    for(int k=0;k<4;k++)
                    {
                        int row1=i+x_next[k];
                        int col1=j+y_next[k];
                        if(row1<0||col1<0||row1>=row||col1>=col||grid[row1][col1]==0)
                        {
                            mp[i*col+j]++;//we will increase the size
                        }
                    }
                }
            }
        }
        int per=0;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            per+=i->second;
        }
        return per;
    }
};
