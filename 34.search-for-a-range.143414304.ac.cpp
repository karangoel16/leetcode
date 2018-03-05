/*
 * [34] Search for a Range
 *
 * https://leetcode.com/problems/search-for-a-range/description/
 *
 * algorithms
 * Medium (31.60%)
 * Total Accepted:    179K
 * Total Submissions: 566.6K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers sorted in ascending order, find the starting and
 * ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * 
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 * 
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res={-1,-1};
        if(nums.size()<1) return res;
        if(nums[0]>target || nums[nums.size()-1]<target) return res;
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]<target)
                low=mid+1;
            else
                high=mid;
        }
        if(nums[low]!=target)
            return res;
        res[0]=low;
        low=0;
        high=nums.size();
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]>target){
                high=mid;
            }
            else
                low=mid+1;
        }
        res[1]=high-1;
        return res;
    }
};
