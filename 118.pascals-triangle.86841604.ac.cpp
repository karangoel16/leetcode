/*
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (39.85%)
 * Total Accepted:    163.1K
 * Total Submissions: 409.4K
 * Testcase Example:  '0'
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 * 
 * 
 * For example, given numRows = 5,
 * Return
 * 
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++)
        {
            vector<int> res;
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                {
                    res.push_back(1);
                }
                else
                {
                    res.push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};
