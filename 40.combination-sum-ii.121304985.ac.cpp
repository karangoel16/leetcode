/*
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (35.63%)
 * Total Accepted:    144.6K
 * Total Submissions: 405.9K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 
 * Given a collection of candidate numbers (C) and a target number (T), find
 * all unique combinations in C where the candidate numbers sums to T.
 * 
 * 
 * Each number in C may only be used once in the combination.
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * 
 * 
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
 * A solution set is: 
 * 
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 */
class Solution {
    set<vector<int>> res;
public:
    int helper(vector<int> result,int target,int pos,vector<int>c)
    {
        if(target==0)
        {
            res.insert(result);
        }
        for(int i=pos;i<c.size() && c[i]<=target;i++)
        {
            //int temp=c[i];
            result.push_back(c[i]);
            helper(result,target-c[i],i+1,c);
            result.pop_back();
        }
        return 0;
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        std::sort(c.begin(),c.end());
        vector<int> result;
        helper(result,target,0,c);
        vector<vector<int>> ret;
        std::copy(res.begin(), res.end(), std::back_inserter(ret));
        return ret;
    }
};
