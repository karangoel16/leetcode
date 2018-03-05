/*
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (46.53%)
 * Total Accepted:    73K
 * Total Submissions: 156.8K
 * Testcase Example:  '1'
 *
 * Follow up for N-Queens problem.
 * 
 * Now, instead outputting board configurations, return the total number of
 * distinct solutions.
 * 
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
    int totalNQueens(int n) {
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
        return result.size();
    }
};
