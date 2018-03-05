/*
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (32.71%)
 * Total Accepted:    114.8K
 * Total Submissions: 350.8K
 * Testcase Example:  '[]\n5'
 *
 * 
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 * 
 * Would this affect the run-time complexity? How and why?
 * 
 * 
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * Write a function to determine if a given target is in the array.
 * 
 * The array may contain duplicates.
 */
bool helper(vector<int> nums,int target,int low, int high)
{
    if(low>high)
    {
        return false;
    }
    int mid=(low+high)/2;
    //std::cout<<nums[mid]<<"\n";
    if(nums[mid]==target)
    {
        return true;
    }
    int flag=1;
    if(nums[low]<nums[high])
    {
        flag=0;
    }
    if(flag==0)
    {   
        //std::cout<<nums[mid]<<"\n";
        if(nums[mid]<target)
        {
            return helper(nums,target,mid+1,high);
        }
        if(nums[mid]>target)
        {
            return helper(nums,target,low,mid-1);
        }
    }
    //std::cout<<nums[mid]<<"\n";
    return helper(nums,target,low,mid-1)||helper(nums,target,mid+1,high);
}
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return helper(nums,target,0,nums.size()-1);
    }
};
