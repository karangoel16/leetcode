/*
 * [750] Contain Virus
 *
 * https://leetcode.com/problems/contain-virus/description/
 *
 * algorithms
 * Hard (38.87%)
 * Total Accepted:    1.1K
 * Total Submissions: 2.9K
 * Testcase Example:  '[[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]]'
 *
 * 
 * A virus is spreading rapidly, and your task is to quarantine the infected
 * area by installing walls.
 * 
 * The world is modeled as a 2-D array of cells, where 0 represents uninfected
 * cells, and 1 represents cells contaminated with the virus.  A wall (and only
 * one wall) can be installed between any two 4-directionally adjacent cells,
 * on the shared boundary.
 * 
 * Every night, the virus spreads to all neighboring cells in all four
 * directions unless blocked by a wall.
 * Resources are limited. Each day, you can install walls around only one
 * region -- the affected area (continuous block of infected cells) that
 * threatens the most uninfected cells the following night. There will never be
 * a tie.
 * 
 * Can you save the day? If so, what is the number of walls required? If not,
 * and the world becomes fully infected, return the number of walls used.
 * 
 * 
 * Example 1:
 * 
 * Input: grid = 
 * [[0,1,0,0,0,0,0,1],
 * ⁠[0,1,0,0,0,0,0,1],
 * ⁠[0,0,0,0,0,0,0,1],
 * ⁠[0,0,0,0,0,0,0,0]]
 * Output: 10
 * Explanation:
 * There are 2 contaminated regions.
 * On the first day, add 5 walls to quarantine the viral region on the left.
 * The board after the virus spreads is:
 * 
 * [[0,1,0,0,0,0,1,1],
 * ⁠[0,1,0,0,0,0,1,1],
 * ⁠[0,0,0,0,0,0,1,1],
 * ⁠[0,0,0,0,0,0,0,1]]
 * 
 * On the second day, add 5 walls to quarantine the viral region on the right.
 * The virus is fully contained.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: grid = 
 * [[1,1,1],
 * ⁠[1,0,1],
 * ⁠[1,1,1]]
 * Output: 4
 * Explanation: Even though there is only one cell saved, there are 4 walls
 * built.
 * Notice that walls are only built on the shared boundary of two different
 * cells.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: grid = 
 * [[1,1,1,0,0,0,0,0,0],
 * ⁠[1,0,1,0,1,1,1,1,1],
 * ⁠[1,1,1,0,0,0,0,0,0]]
 * Output: 13
 * Explanation: The region on the left only builds two new walls.
 * 
 * 
 * 
 * Note:
 * 
 * The number of rows and columns of grid will each be in the range [1, 50].
 * Each grid[i][j] will be either 0 or 1.
 * Throughout the described process, there is always a contiguous viral region
 * that will infect strictly more uncontaminated squares in the next round.
 * 
 * 
 */
struct node{
    int walls;
    vector<pair<int,int>> index;
    set<pair<int,int>> st;
    node(){
        walls=0;
    }
};

class Solution {
public:
    int containVirus(vector<vector<int>>& grid) {
        int res=0,c=1;
        vector<int>x_mov{0,0,1,-1};
        vector<int>y_mov{-1,1,0,0};
        int row=grid.size();
        if(!row)
            return 0;
        int col=grid[0].size();
        while(true){
            vector<node> areas;
            int mx=0;
            int idx=-1;
            for(int i=0;i<row;i++)
                for(int j=0;j<col;j++)
                    if(grid[i][j]==c){
                        areas.push_back(node());
                        node *temp=&areas[areas.size()-1];
                        temp->index.push_back(make_pair(i,j));
                        grid[i][j]=c+1;
                        queue<pair<int,int>> que;
                        que.push(make_pair(i,j));
                        while(!que.empty()){
                            auto val=que.front();
                            que.pop(); // we will remove values from the queue
                            for(int k=0;k<4;k++){
                                int x_temp=val.first+x_mov[k];
                                int y_temp=val.second+y_mov[k];
                                if(x_temp<row && y_temp<col && y_temp>=0 && x_temp>=0){
                                    if(grid[x_temp][y_temp]==c){
                                        temp->index.push_back(make_pair(x_temp,y_temp));
                                        grid[x_temp][y_temp]=(c+1);
                                        que.push(make_pair(x_temp,y_temp));
                                    }
                                    else if(grid[x_temp][y_temp]==0){
                                        temp->st.insert(make_pair(x_temp,y_temp));
                                        temp->walls++;
                                    }
                                }
                            }
                        }
                        if(temp->st.size()>mx){
                            mx=temp->st.size();
                            idx=areas.size()-1;
                        }
                    }
            if(mx==0)
                break;
            c++;
            for(auto i:areas[idx].index)
                grid[i.first][i.second]=-1;
            res+=areas[idx].walls;
            areas[idx].st.clear();   
            for(auto i:areas)
                for(auto p:i.st)
                    grid[p.first][p.second]=c;        
        }
        return res;
    }
};
