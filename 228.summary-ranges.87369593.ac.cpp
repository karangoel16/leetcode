/*
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Medium (31.79%)
 * Total Accepted:    95.4K
 * Total Submissions: 300K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * 
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.
 * 
 * Example 1:
 * 
 * Input: [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * 
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        if(nums.size()==0)
        {
            return res;
        }
        int start=nums[0];
        int end=nums[0];
        int flag=1;
        for(int i=1;i<nums.size();i++)
        {
            //std::cout<<nums[i]<<std::endl;
            if(nums[i]==(end+1))
            {
                flag=1;
                end=nums[i];
            }
            else
            {
                flag=0;
                if(start==end)
                {
                    res.push_back(to_string(start));
                }
                else
                {
                    res.push_back(to_string(start)+"->"+to_string(end));
                }
                start=nums[i];
                end=nums[i];
                std::cout<<nums[i];
            }
        }
        if(start==end)
            {
                res.push_back(to_string(start));
            }
            else
            {
                res.push_back(to_string(start)+"->"+to_string(end));
            }
        return res;
    }
};
