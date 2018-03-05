/*
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (38.01%)
 * Total Accepted:    139.9K
 * Total Submissions: 367.9K
 * Testcase Example:  '[1,2,2]'
 *
 * 
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * 
 * For example,
 * If nums = [1,2,2], a solution is:
 * 
 * 
 * 
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
void support(vector<vector<int>> & res,vector<int> nums,int digit,vector<int> temp,map<vector<int>,int> & mul)
{
    if(digit>nums.size())
    {
        return ;
    }
    if(mul.find(temp)!=mul.end())
    {
        return ;
    }
    else
    {
        mul[temp]=1;
        res.push_back(temp);//this is done to push the temp into the array
    }
    for(int i=digit;i<nums.size();i++)
    {
        temp.push_back(nums[i]);
        support(res,nums,i+1,temp,mul);
        temp.pop_back();
    }
}
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<vector<int>,int> mul;
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        support(res,nums,0,temp,mul);
        return res;
    }
};
