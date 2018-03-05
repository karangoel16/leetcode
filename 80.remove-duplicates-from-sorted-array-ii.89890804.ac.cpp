/*
 * [80] Remove Duplicates from Sorted Array II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
 *
 * algorithms
 * Medium (36.72%)
 * Total Accepted:    143.2K
 * Total Submissions: 389.9K
 * Testcase Example:  '[]'
 *
 * 
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 * 
 * 
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 * 
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new
 * length.
 * 
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        unordered_map<int,int> test;
        for(int i=0;i<nums.size();i++)
        {
            if(test[nums[i]]==2)
            {
                nums[i]=INT_MAX;
            }
            else
            {
                test[nums[i]]++;
            }
        }
        int j=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=INT_MAX)
            {
                j++;
                nums[j]=nums[i];
            }
        }
        return j+1;
    }
};
