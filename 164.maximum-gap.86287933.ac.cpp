/*
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (29.99%)
 * Total Accepted:    54.4K
 * Total Submissions: 181.4K
 * Testcase Example:  '[]'
 *
 * Given an unsorted array, find the maximum difference between the successive
 * elements in its sorted form.
 * 
 * Try to solve it in linear time/space.
 * 
 * Return 0 if the array contains less than 2 elements.
 * 
 * You may assume all elements in the array are non-negative integers and fit
 * in the 32-bit signed integer range.
 * 
 * Credits:Special thanks to @porker2008 for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2)
        {
            return 0;
        }
        priority_queue<int,vector<int>,std::greater<int>> pr;
        for(int i=0;i<nums.size();i++)
        {
            pr.push(nums[i]);
        }
        int dis=pr.top();
        int res=0;
        while(!pr.empty())
        {
            dis=pr.top()-dis;
            //std::cout<<dis<<"\n";
            if(res<dis)
            {
                res=dis;
            }
            dis=pr.top();
            pr.pop();
        }
        return res;
    }
};
