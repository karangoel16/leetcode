/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (37.47%)
 * Total Accepted:    821.5K
 * Total Submissions: 2.2M
 * Testcase Example:  '[3,2,4]\n6'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map_;
        for(int i=0;i<nums.size();i++)
        {
            map_[nums[i]]=i;
        }
        vector<int> temp;
        for(int i=0;i<nums.size();i++)
        {
            int comp=target-nums[i];
            std::unordered_map<int,int>::iterator it=map_.find(comp);
            if(it!=map_.end() && i!=map_[comp])
            {
                temp.push_back(i);
                temp.push_back(map_[comp]);
                break;
            }
        }
        return temp;
    }
};
