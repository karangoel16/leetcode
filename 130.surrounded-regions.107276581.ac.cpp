/*
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (19.44%)
 * Total Accepted:    98.1K
 * Total Submissions: 504.5K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * 
 * 
 * For example,
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * 
 * 
 * After running your function, the board should be:
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 */
class union_find{
    unordered_map<int,int> mp;
    public:
    union_find(int i)
    {
        for(int k=0;k<=i;k++)
        {
            mp[k]=k;//this is to define the initial node
        }
    }
    int find(int p)
    {
        int root=p;
        while(mp[root]!=root)
        {
            root=mp[root];
        }
        int t=p;
        while(mp[t]!=root)
        {
            int temp=mp[t];
            mp[t]=root;
            t=temp;
        }
        return root;
    }
    bool isConnected(int p,int q)
    {
        return find(p)==find(q);
    }
    void Cunion(int p,int q)
    {
        int rootq=find(q);
        int rootp=find(p);
        //std::cout<<rootq<<" "<<rootp<<"\n";
        if(rootq==rootp)
        {
            return ;
        }
        mp[rootq]=rootp;
    }
};
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        if(row==0)
        {
            return ;
        }
        int col=board[0].size();
        union_find uf = union_find(row*col+1);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if((i==0||i==row-1||j==0||j==col-1)&&board[i][j]=='O')
                {
                    uf.Cunion(i*col+j,row*col+1);
                }
                else if(board[i][j]=='O')
                {
                    if(board[i-1][j]=='O')
                    {
                        uf.Cunion((i-1)*col+j,i*col+j);
                    }
                    if(board[i+1][j]=='O')
                    {
                        uf.Cunion((i+1)*col+j,i*col+j);
                    }
                    if(board[i][j+1]=='O')
                    {
                        uf.Cunion((i)*col+(j+1),i*col+j);
                    }
                    if(board[i][j-1]=='O')
                    {
                        uf.Cunion(i*col+j-1,i*col+j);
                    }
                }
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(!uf.isConnected(i*col+j,row*col+1))
                {
                    board[i][j]='X';
                }
            }
        }
        
    }
};
