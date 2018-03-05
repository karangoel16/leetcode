/*
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (34.72%)
 * Total Accepted:    154.6K
 * Total Submissions: 445.2K
 * Testcase Example:  '[1,1,2]'
 *
 * 
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * 
 * 
 * For example,
 * [1,1,2] have the following unique permutations:
 * 
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    int helper(vector<int> nums,int i,int j,vector<vector<int>> &res)
    {
        if(i==j)
        {
            res.push_back(nums);
            return 1;
        }
        for(int k=i;k<j;k++)
        {
            if(i!=k && nums[i]==nums[k])continue;
            std::swap(nums[i],nums[k]);
            helper(nums,i+1,j,res);
        }
        return 0;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        helper(nums,0,nums.size(),res);
        return res;
    }
};
