/*
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (27.96%)
 * Total Accepted:    167.2K
 * Total Submissions: 597.9K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * 
 * 
 * For example,
 * Given board = 
 * 
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 * 
 */
vector<int> x_mov{1,-1,0,0};
vector<int> y_mov{0,0,-1,1};
bool check(int row,int col,vector<vector<char>> &board)
{
    int r=board.size();
    int c=board[0].size();
    if(row>=0 && row<r && col>=0 && col<c && board[row][col]!='*')
    {
        //std::cout<<row<<" "<<col<<board[row][col]<<"\n";
        return true;
    }
    return false;
}
bool game(string s,vector<vector<char>> &board,int i,int row,int col)
{
    if(s[i]!=board[row][col])
    {
        return false;
    }
    if(s.length()-1==i)
    {
        return true;
    }
    //std::cout<<board[row][col]<<" "<<i<<"\n";
    char ch=board[row][col];
    board[row][col]='*';
        //std::cout<<s[i]<<"\n";
        for(int j=0;j<4;j++)
        {
            int row_next=row+x_mov[j];
            int col_next=col+y_mov[j];
            if(check(row_next,col_next,board)&&game(s,board,i+1,row_next,col_next))
            {
                return true;
            }
        }
    board[row][col]=ch;
    return false;
}
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //vector<vector<bool>> mul(board.size(),std::vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(game(word,board,0,i,j))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
