/*
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (50.24%)
 * Total Accepted:    139.9K
 * Total Submissions: 278.4K
 * Testcase Example:  '[0,0]'
 *
 * 
 * Given an array of n integers where n > 1, nums, return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Solve it without division and in O(n).
 * 
 * For example, given [1,2,3,4], return [24,12,8,6].
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array
 * does not count as extra space for the purpose of space complexity analysis.)
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,1);
        int prod_low=1;
        int prod_high=1;
        for(int i=0;i<n;i++)
        {
            res[i]=res[i]*prod_low;
            res[n-1-i]=res[n-1-i]*prod_high;
            prod_low=prod_low*nums[i];
            prod_high=prod_high*nums[n-1-i];
        }
        /*for(int i=nums.size()-1;i>=0;i--)
        {
            res[i]=res[i]*prod_high;
            prod_high=prod_high*nums[i];
        }*/
        return res;
    }
};
