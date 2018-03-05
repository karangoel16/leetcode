/*
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (46.73%)
 * Total Accepted:    221K
 * Total Submissions: 473K
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Given a collection of distinct numbers, return all possible permutations.
 * 
 * 
 * 
 * For example,
 * [1,2,3] have the following permutations:
 * 
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
vector <vector <int>> result;
void p(vector <int> &nums,vector <int> &permuted,int j)
{
    if(nums.size()==0)
    {
        return;
    }
    //vector <int> temp1;
    if(nums.size()==permuted.size())
    {
        vector <int> temp1(permuted);
        std::sort(temp1.begin(),temp1.end());
        int i=0;
        int flag=1;
        while(i<nums.size())
        {
            if(nums[i]!=temp1[i])
            {
                flag=0;
                break;
            }
            ++i;
        }
        if(flag)
        result.push_back(permuted);
    }
    vector <vector<int>> temp;
    if(nums.size()>permuted.size())
    {
        int i=0;
        while(i<nums.size())
        {
            permuted.push_back(nums[i]);
            p(nums,permuted,i+1);
            permuted.pop_back();
            i++;
        }
    }
}
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        if(nums.size()==0)
        {
            return result;
        }
        std:sort(nums.begin(),nums.end());
        vector <int> perm;
        p(nums,perm,0);
        return result;
    }
};
