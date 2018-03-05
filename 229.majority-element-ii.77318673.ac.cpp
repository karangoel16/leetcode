/*
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (29.10%)
 * Total Accepted:    68.1K
 * Total Submissions: 234.2K
 * Testcase Example:  '[]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
 */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector <int> temp;
        if(nums.size()==0)
        {
            return temp;
        }
        else
        {
            int i=0;
            std::sort(nums.begin(),nums.end());
            while(i<nums.size())
            {
                int j=1;
                while(nums[i]==nums[i+1] && i<nums.size())
                {
                    ++i;
                    ++j;
                }
                //std::cout<<j<<std::endl;
                if(j>nums.size()/3)
                {
                    temp.push_back(nums[i]);
                }
                ++i;
            }
        }
        return temp;
    }
};
