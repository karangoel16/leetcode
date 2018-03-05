/*
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (39.05%)
 * Total Accepted:    103.6K
 * Total Submissions: 265.2K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * 
 * 
 * For example,
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * Given target = 5, return true.
 * Given target = 20, return false.
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)
        {
            return false;
        }
        int row_end=matrix.size()-1;
        int col_end=matrix[0].size()-1;
        int row_start=0;
        int col_start=0;
        while(row_start<=row_end && col_end>=col_start)
        {
            if(matrix[row_start][col_end]==target)
            {
                return true;
            }
            if(row_start<=row_end && col_end>=col_start && matrix[row_start][col_end]>target)
            {
                col_end--;
            }
            if(row_start<=row_end && col_end>=col_start && matrix[row_start][col_end]<target)
            {
                row_start++;
            }
        }
        return false;
    }
};
