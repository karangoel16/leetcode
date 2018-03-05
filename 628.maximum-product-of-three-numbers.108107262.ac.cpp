/*
 * [628] Maximum Product of Three Numbers
 *
 * https://leetcode.com/problems/maximum-product-of-three-numbers/description/
 *
 * algorithms
 * Easy (44.70%)
 * Total Accepted:    31.2K
 * Total Submissions: 69.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array, find three numbers whose product is maximum and
 * output the maximum product.
 * 
 * Example 1:
 * 
 * Input: [1,2,3]
 * Output: 6
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4]
 * Output: 24
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array will be in range [3,104] and all elements are
 * in the range [-1000, 1000].
 * Multiplication of any three numbers in the input won't exceed the range of
 * 32-bit signed integer.
 * 
 * 
 */
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size()<3)
        {
            return 0;
        }
        int max=INT_MIN;
        std::sort(nums.begin(),nums.end());
        int res=nums[0]*nums[1]*nums[nums.size()-1];
        max=max>(res)?max:res;
        std::reverse(nums.begin(),nums.end());
        res=nums[0]*nums[1]*nums[2];
        max=max>res?max:res;
        return max;
    }
};