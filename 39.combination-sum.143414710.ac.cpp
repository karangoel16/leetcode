/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (40.97%)
 * Total Accepted:    206.7K
 * Total Submissions: 504.4K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 
 * Given a set of candidate numbers (C) (without duplicates) and a target
 * number (T), find all unique combinations in C where the candidate numbers
 * sums to T. 
 * 
 * 
 * The same repeated number may be chosen from C unlimited number of times.
 * 
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * 
 * 
 * For example, given candidate set [2, 3, 6, 7] and target 7, 
 * A solution set is: 
 * 
 * [
 * ⁠ [7],
 * ⁠ [2, 2, 3]
 * ]
 * 
 * 
 */
class Solution {
    vector<vector<int>> res;
public:
    int helper(vector<int>& result,int target,int pos,vector<int>c)
    {
        if(target==0)
        {
            res.push_back(result);
            return 0;
        }
        for(int i=pos;i<c.size() && c[i]<=target;i++)
        {
                result.push_back(c[i]);
                helper(result,target-c[i],i,c);
                result.pop_back();
        }
        return 0;
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        std::sort(c.begin(),c.end());
        vector<int> result;
        helper(result,target,0,c);
        return res;
    }
};
