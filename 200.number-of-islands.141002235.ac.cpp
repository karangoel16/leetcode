/*
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (36.34%)
 * Total Accepted:    161K
 * Total Submissions: 443.1K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 11110110101100000000
 * Answer: 1
 * Example 2:
 * 11000110000010000011
 * Answer: 3
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class uf
{
    private:
    int count;
    unordered_map<int,int> mp;
    public:
    uf(int n)
    {
        count=n;//this is to setup different routes
        for(int i=0;i<n;i++)
        {
            mp[i]=i;//this gives same values to the nodes and connect to the data structure in the main program
        }
    }
    int getcount(){
        return count;
    }
    int find(int i)
    {
        int root=i;
        while(mp[root]!=root)
        {
            root=mp[root];
        }
        int p=i;
        while(mp[p]!=root){
            int temp=mp[p];
            mp[p]=root;
            p=temp;
        }
        return root;
    }
    void unionfind(int p,int q)
    {
        int rootp=find(p);
        int rootq=find(q);
        if(rootp==rootq)
            {
                return ;
        }
        mp[rootp]=rootq;
        count--;
        return;
    }
    bool connected(int p,int q)
    {
        return find(p)==find(q);//it is connected if the two components gives out same result of the union find
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        unordered_map<int,int> mp;
        int row=grid.size();
        if(row==0)
        {
            return 0;
        }
        int col=grid[0].size();//this is for column size
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    mp[i+col*j]=count++;
                }
            }
        }
        //here we will begin adding the Union find data structure of the entire stuff
        uf graph(count);//this will give me uf value of the graph
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1' && j+1<col && grid[i][j+1]=='1')
                {
                    graph.unionfind(mp[i+col*j],mp[i+col*(j+1)]);//this is when the right is joined together
                }
                if(grid[i][j]=='1' && i+1<row && grid[i+1][j]=='1')
                {
                    graph.unionfind(mp[i+col*j],mp[i+1+col*j]);
                }
                
            }
        }
        return graph.getcount();
    }
};

