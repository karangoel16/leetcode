/*
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (27.46%)
 * Total Accepted:    148.3K
 * Total Submissions: 540.1K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array S of n integers, are there elements a, b, c, and d in S such
 * that a + b + c + d = target? Find all unique quadruplets in the array which
 * gives the sum of target.
 * 
 * Note: The solution set must not contain duplicate quadruplets.
 * 
 * 
 * 
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4)
        {
            return res;
        }
        std::sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++)
        {
            if(i>=1 && nums[i]==nums[i-1])
            {
                continue;
            }
            for(int j=i+1;j<nums.size()-2;j++)
            {
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target)break;
                if(j>(i+1) && nums[j]==nums[j-1]) continue; //this is to check if the duplicate element exist
                int low=j+1;
                int high=nums.size()-1;
                while(low<high)
                {
                    int sum=nums[high]+nums[low]+nums[i]+nums[j];
                    //std::cout<<nums[i]<<" "<<nums[j]<<" "<<nums[low]<<" "<<nums[high]<<" "<<sum<<"\n";
                    if(sum==target)
                    {
                        res.push_back(vector<int>{nums[i],nums[j],nums[low],nums[high]});
                        while(low<high&&nums[low]==nums[low+1])low++; //skipping over duplicate on low
                        while(low<high&&nums[high]==nums[high-1])high--; //skipping over duplicate on high
                        low++; 
                        high--;
                    }
                    else if(sum<target)
                        low++;
                    else
                        high--;
                }
            }
        }
        return res;
    }
};
