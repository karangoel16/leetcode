/*
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (46.89%)
 * Total Accepted:    202.8K
 * Total Submissions: 432.4K
 * Testcase Example:  '[]'
 *
 * 
 * Given an array of integers, find if the array contains any duplicates. Your
 * function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 * 
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> temp;
        for(int i=0;i<nums.size();i++)
            if(!temp.insert(nums[i]).second)
                return true;
        return false;
    }
};
