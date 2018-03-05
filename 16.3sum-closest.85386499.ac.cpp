/*
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (31.61%)
 * Total Accepted:    165.3K
 * Total Submissions: 523K
 * Testcase Example:  '[0,0,0]\n1'
 *
 * Given an array S of n integers, find three integers in S such that the sum
 * is closest to a given number, target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 * 
 * 
 * ⁠   For example, given array S = {-1 2 1 -4}, and target = 1.
 * 
 * ⁠   The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)
        {
            return 0;
        }
        int res;
        long res_less=INT_MIN;
        long res_more=INT_MAX;
        std::sort(nums.begin(),nums.end());
        if(nums.size()==3)
        {
            return nums[0]+nums[1]+nums[2];
        }
        for(int i=0;i<nums.size();i++)
        {
            int val=target-nums[i];
            if(i!=0 && nums[i]==nums[i-1])continue;
            for(int j=i+1,k=nums.size()-1;j<k;)
            {
                if(nums[j]+nums[k]==val)
                {
                    std::cout<<"*";
                    return nums[i]+nums[j]+nums[k];
                }
                if((nums[j]+nums[k])<val)
                {
                    int res=nums[i]+nums[j]+nums[k];
                    if(res>res_less)
                    {
                        res_less=res;
                    }
                    j++;
                }
                if(nums[j]+nums[k]>val)
                {
                    int res=nums[i]+nums[j]+nums[k];
                    if(res<res_more)
                    {
                        res_more=res;
                    }
                    k--;
                }
            }
        };
        return abs(res_more-target)>=abs(target-res_less)?res_less:res_more;
    }
};
