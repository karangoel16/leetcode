/*
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (30.18%)
 * Total Accepted:    82.9K
 * Total Submissions: 274.8K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * 
 * For example, given the following matrix:
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Return 4.
 * 
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        if(!row)
            return row;
        int col=matrix[0].size();
        vector<int> cur(col+1,0);
        vector<int> pre(col+1,0);
        int Max=0;
        //cout<<Max<<"\t";
        for(int i=1;i<=row;i++){
            //cur[1]=matrix[i-1][0]-'0';
            //Max=std::max(Max,cur[0]);  
            for(int j=1;j<=col;j++){
                if(matrix[i-1][j-1]=='1')
                {
                    //std::cout<<cur[j-1]<<" "<<pre[j-1]<<" "<<pre[j]<<"*\n";
                    cur[j]=min(cur[j-1],min(pre[j-1],pre[j]))+1;
                    Max=std::max(Max,cur[j]);
                }
                else
                    cur[j]=0;
            }
            pre=cur;
            //cout<<Max<<"\t";
        }
        return Max*Max;
    }
};
