/*
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (34.75%)
 * Total Accepted:    127.3K
 * Total Submissions: 366.2K
 * Testcase Example:  '[[-10]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * 
 * For example, given the following triangle
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * 
 * 
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        if(!row)
            return 0;
        for(int i=0;i<row-1;i++){
            vector<int> temp(triangle[i+1].size(),INT_MAX);
            for(int j=0;j<triangle[i].size();j++){
                temp[j]=min(triangle[i][j],temp[j]);
                temp[j+1]=min(triangle[i][j],temp[j+1]);
            }
            for(int j=0;j<triangle[i+1].size();j++)
                triangle[i+1][j]+=temp[j];
        }
        return *min_element(triangle[row-1].begin(),triangle[row-1].end());
    }
};
