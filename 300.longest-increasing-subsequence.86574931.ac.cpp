/*
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (38.90%)
 * Total Accepted:    116K
 * Total Submissions: 298.1K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * 
 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18],
 * The longest increasing subsequence is [2, 3, 7, 101], therefore the length
 * is 4. Note that there may be more than one LIS combination, it is only
 * necessary for you to return the length.
 * 
 * 
 * Your algorithm should run in O(n2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity? 
 * 
 * Credits:Special thanks to @pbrother for adding this problem and creating all
 * test cases.
 */
class Solution {
    int helper(vector<int> &temp,int low,int high,int key)
    {
    while(low<=high){
        int mid=low+((high-low)>>1);
        if(temp[mid]==key)
            return mid;
        else if(temp[mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> temp(nums.size(),0);
        temp[0]=nums[0];
        int length=1;
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]<temp[0])
                temp[0]=nums[i];
            else if(nums[i]>temp[length-1])
                temp[length++]=nums[i];//this is done to add new element in the array 
            else
                temp[helper(temp,0,length-1,nums[i])]=nums[i];
        }
        return length;
    }
};
