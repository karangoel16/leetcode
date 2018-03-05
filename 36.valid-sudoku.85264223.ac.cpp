/*
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (37.32%)
 * Total Accepted:    147K
 * Total Submissions: 393.9K
 * Testcase Example:  '[[".","8","7","6","5","4","3","2","1"],["2",".",".",".",".",".",".",".","."],["3",".",".",".",".",".",".",".","."],["4",".",".",".",".",".",".",".","."],["5",".",".",".",".",".",".",".","."],["6",".",".",".",".",".",".",".","."],["7",".",".",".",".",".",".",".","."],["8",".",".",".",".",".",".",".","."],["9",".",".",".",".",".",".",".","."]]'
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 * 
 * 
 * 
 * A partially filled sudoku which is valid.
 * 
 * 
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only
 * the filled cells need to be validated.
 * 
 */
bool support(vector<int> temp)
{
    unordered_map<int,int> map_;
    unordered_map<int,int>::iterator it;
    for(int i=0;i<temp.size();i++)
    {
        it=map_.find(temp[i]);
        if(it!=map_.end())
        {
            return true;
        }
        else
        {
            map_[temp[i]]=1;
        }
    }
    return false;
}
class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> temp_row;
        vector<int> temp_col;
        vector<int> temp_box;
        for(int i=0;i<9;i++)
        {
            temp_row.clear();
            temp_col.clear();
            for(int j=0;j<9;j++)
            {
                if(isdigit(board[i][j]))
                {
                    temp_col.push_back((int)board[i][j]-48);
                }
                if(isdigit(board[j][i]))
                    temp_row.push_back((int)board[j][i]-48);
            }
            if(support(temp_col)||support(temp_row))
            {
                return false;
            }
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                temp_box.clear();
                for(int t=0;t<3;t++)
                {
                    for(int k=0;k<3;k++)
                    {
                        if(isdigit(board[3*i+t][3*j+k]))
                        {
                            temp_box.push_back((int)board[3*i+t][3*j+k]-48);
                        }
                    }
                }
                if(support(temp_box))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
