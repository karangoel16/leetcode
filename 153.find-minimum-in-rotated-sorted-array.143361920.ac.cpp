/*
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (40.72%)
 * Total Accepted:    185.6K
 * Total Submissions: 455.8K
 * Testcase Example:  '[1]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int mid=0;
        while(low<high)
        {
            if(nums[low]<nums[high])
            {
                return nums[low];
            }
            int mid=(low+high)/2;
            if(nums[mid]>=nums[low])
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return nums[low];
    }
};
