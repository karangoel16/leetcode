/*
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (27.11%)
 * Total Accepted:    134K
 * Total Submissions: 494.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * 
 * 
 * For example,
 * Given the following matrix:
 * 
 * 
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 
 * 
 * You should return [1,2,3,6,9,8,7,4,5].
 * 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        vector<int> res;
        if(!row)
            return res;
        int col=matrix[0].size();
        vector<int> x_mov={1,0,-1,0};
        vector<int> y_mov={0,1,0,-1};
        int val=max(row,col);
        int flag=0,X=0,Y=-1;
        res=vector<int>(row*col,0);
        int result=0;
        for(int i=0;i<2*val;i++)
        {
            for(int j=0;j<val;j++){
                int X_temp=X+y_mov[flag];
                int Y_temp=Y+x_mov[flag];
                //std::cout<<X_temp<<" "<<Y_temp<<" "<<flag<<"\n";
                if(X_temp>= 0 && Y_temp>=0 && X_temp<row && Y_temp<col && matrix[X_temp][Y_temp]!=INT_MAX){
                    res[result++]=matrix[X_temp][Y_temp];
                    matrix[X_temp][Y_temp]=INT_MAX;
                    X=X_temp;
                    Y=Y_temp;
                }
                else{
                    break;
                }
            }
            flag=(flag+1)%4;
        }
        return res;
    }
};
