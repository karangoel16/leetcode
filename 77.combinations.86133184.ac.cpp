/*
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (41.00%)
 * Total Accepted:    138.2K
 * Total Submissions: 337K
 * Testcase Example:  '4\n2'
 *
 * 
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * 
 * For example,
 * If n = 4 and k = 2, a solution is:
 * 
 * 
 * 
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
class Solution {
    vector<vector<int>> res;
    vector<int> temp;
public:
    int support(int i,int n,int k)
    {
        if(temp.size()==k)
        {
            res.push_back(temp);
            return 0;
        }
        for(int j=i;j<=n;j++)
        {
            temp.push_back(j);
            support(j+1,n,k);
            temp.pop_back();
        }
        return 0;
    }
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        temp.clear();
        support(1,n,k);
        return res;
    }
};
