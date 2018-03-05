/*
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (32.96%)
 * Total Accepted:    95.6K
 * Total Submissions: 290.2K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 * 
 * [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 
 */
class Solution {
    vector<vector<string>>result;
    vector <string> board;
public:
    bool check(int row,int col)
    {
        for(int i=0;i<board.size();i++)
        {
            if(board[row][i]=='Q')
            {
                return false;
            }
            
        }
        int i=row;
        int j=col;
        while(i>=0 && j>=0)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
            --i;
            --j;
        }
        i=row;
        j=col;
        while(j>=0 && i<board.size())
        {
            if(board[i][j]=='Q')
                return false;
            ++i;
            --j;
        }
        return true;
    }
    void place(int col)
    {
        if(col>=board.size())
        {
            int res=std::find(result.begin(),result.end(),board)-result.begin();
            if(res==result.size())
            {
                result.push_back(board);
            }
        }
        for(int i=0;i<board.size();i++)
        {
            if(check(i,col))
            {
                board[i][col]='Q';
                place(col+1);
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
            board.clear();
            for(int i=0;i<n;i++)
            {
                string temp;
                for(int j=0;j<n;j++)
                {
                    temp.push_back('.');
                }
                board.push_back(temp);
            }
            place(0);
        return result;
    }
};
