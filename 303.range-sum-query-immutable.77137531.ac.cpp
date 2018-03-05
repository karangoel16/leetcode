/*
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (31.82%)
 * Total Accepted:    89.9K
 * Total Submissions: 282.6K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * Example:
 * 
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 * 
 */
class NumArray {
    vector<int>nums1;
public:
    NumArray(vector<int> &nums) {

        if(nums.size()!=0)
        {

            if(nums1.size()==0)
            {
                nums1.push_back(nums[0]);
            }
            for(int i=1;i<nums.size();++i)
            {

                nums1.push_back(nums1[i-1]+nums[i]);
            }
        }
    }

    int sumRange(int i, int j) {
        if(nums1.size()==0)
        {
            return 0;
        }
        if(i==0)
        {
            return nums1[j];
        }
        else
        {
            return nums1[j]-nums1[i-1];
        }
    }
};
