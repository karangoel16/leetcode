/*
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (44.13%)
 * Total Accepted:    220.1K
 * Total Submissions: 498.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * 
 * For example,
 * If nums = [1,2,3], a solution is:
 * 
 * 
 * 
 * [
 * ⁠ [3],
 * ⁠ [1],
 * ⁠ [2],
 * ⁠ [1,2,3],
 * ⁠ [1,3],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
void support(vector<vector<int>> & res,vector<int> nums,int digit,vector<int> temp)
{
    if(digit>nums.size())
    {
        return ;
    }
    //if(mul.find(temp)!=mul.end())
    //{
    //    return ;
    //}
    //else
    //{
    //    mul[temp]=1;
        res.push_back(temp);//this is done to push the temp into the array
    //}
    for(int i=digit;i<nums.size();i++)
    {
        //if(te_map.find(nums[i])==te_map.end())
        //{
         //   te_map[nums[i]]=1;
            temp.push_back(nums[i]);
            support(res,nums,i+1,temp);
            temp.pop_back();
        //    te_map.erase(nums[i]);
        //}
    }
}
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //map<vector<int>,int> mul;
        //unordered_map<int,int> te;
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        support(res,nums,0,temp);
        return res;
    }
};
