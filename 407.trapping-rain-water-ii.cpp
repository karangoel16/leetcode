/*
 * [407] Trapping Rain Water II
 *
 * https://leetcode.com/problems/trapping-rain-water-ii/description/
 *
 * algorithms
 * Hard (37.96%)
 * Total Accepted:    15.7K
 * Total Submissions: 41.4K
 * Testcase Example:  '[[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]'
 *
 * Given an m x n matrix of positive integers representing the height of each
 * unit cell in a 2D elevation map, compute the volume of water it is able to
 * trap after raining.
 * 
 * 
 * Note:
 * Both m and n are less than 110. The height of each unit cell is greater than
 * 0 and is less than 20,000.
 * 
 * 
 * Example:
 * 
 * Given the following 3x6 height map:
 * [
 * ⁠ [1,4,3,1,3,2],
 * ⁠ [3,2,1,3,2,4],
 * ⁠ [2,3,3,2,3,1]
 * ]
 * 
 * Return 4.
 * 
 * 
 * 
 * 
 * 
 * The above image represents the elevation map
 * [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.
 * 
 * 
 * 
 * 
 * After the rain, water is trapped between the blocks. The total volume of
 * water trapped is 4.
 * 
 */
#define ipair pair<int,int>
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int row=heightMap.size();
        if(!row)
            return 0;
        int col=heightMap[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        auto comp=[&](const ipair &a,const ipair &b){
            return heightMap[a.first][a.second]>heightMap[b.first][b.second];
        };
        int max=INT_MIN;
        priority_queue<ipair,vector<ipair>, decltype(comp)> pq(comp);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 || i==row-1 || j==0 || j==col-1){
                    pq.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        int res=0;
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            max=std::max(max,heightMap[temp.first][temp.second]);
            for(auto i:dir){
                int x_temp=temp.first+i[0];
                int y_temp=temp.second+i[1];
                if(x_temp<0 || x_temp>=row || y_temp<0 || y_temp>=col || visited[x_temp][y_temp])
                    continue;
                visited[x_temp][y_temp]=true;
                if(heightMap[x_temp][y_temp]<max)
                    res += max - heightMap[x_temp][y_temp];
                pq.push({x_temp,y_temp});
            }
        }
        return res;
    }
};
