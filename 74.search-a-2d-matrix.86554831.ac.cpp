/*
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (34.74%)
 * Total Accepted:    151.2K
 * Total Submissions: 435.2K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
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
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * 
 * 
 * Given target = 3, return true.
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)
        {
            return false;
        }
        int col_end=matrix[0].size()-1;
        int row_end=matrix.size()-1;
        int row_start=0;
        int col_start=0;
        if(target>matrix[row_end][col_end] || target<matrix[row_start][col_start])
        {
            return false;
        }
        while(row_start<=row_end)
        {
            int mid=(row_start+row_end)/2;
            //std::cout<<row_start<<"\n";
            if(target>=matrix[mid][col_start] && target<=matrix[mid][col_end])
            {
                row_start=mid;
                break;
            }
            else if(target>matrix[mid][col_end])
            {
                row_start=mid+1;
            }
            else if(target<matrix[mid][col_start])
            {
                row_end=mid-1;
            }
        }
        
        if(row_start>row_end)
        {
            return false;
        }
        while(col_start<=col_end)
        {
            int mid=(col_start+col_end)/2;
            if(matrix[row_start][mid]==target)
            {
                return true;
            }
            else if(matrix[row_start][mid]<target)
            {
                col_start=mid+1;
            }
            else if(matrix[row_start][mid]>target)
            {
                col_end=mid-1;
            }
        }
        return false;
    }
};
