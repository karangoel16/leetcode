/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.80%)
 * Total Accepted:    299.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a
 * + b + c = 0? Find all unique triplets in the array which gives the sum of
 * zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * 
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3)
        {
            return res;
        }
        std::sort(nums.begin(),nums.end(),std::greater<int>());
        /*for(auto i:nums)
        {
            std::cout<<i<<"\n";
        }*/
        for(int i=0;i<nums.size()-2;i++)
        {
            int j=i+1;
            int k=nums.size()-1;
            if(i>=1 && nums[i]==nums[i-1])
            {
                continue;
            }
            //std::cout<<nums[i]<<"\n";
            while(j<k)
            {
                while(j>(i+1) && nums[j]==nums[j-1])
                {
                    j++;
                }
                while(k<nums.size()-1 && nums[k]==nums[k+1])
                {
                    k--;
                }
                if(j<k&&-1*nums[i]==nums[j]+nums[k])
                {
                    //this is the number
                    res.push_back(vector<int>{nums[k],nums[j],nums[i]});
                    j++;
                    k--;
                }
                if(-1*nums[i]>nums[j]+nums[k])
                {
                    k--;
                }
                if(-1*nums[i]<nums[j]+nums[k])
                {
                    j++;
                }

            }
        }
        return res;
    }
};
