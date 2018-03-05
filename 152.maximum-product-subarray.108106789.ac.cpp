/*
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (26.62%)
 * Total Accepted:    132K
 * Total Submissions: 495.8K
 * Testcase Example:  '[-2]'
 *
 * 
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest product.
 * 
 * 
 * 
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 * 
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(!nums.size())
        {
            return 0;
        }
        int maxprehere=nums[0];
        int minprehere=nums[0];
        int maxsofar=nums[0];
        int minhere=nums[0];
        int maxhere=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            maxhere=max(max(maxprehere*nums[i],minprehere*nums[i]),nums[i]);
            minhere=min(min(minprehere*nums[i],maxprehere*nums[i]),nums[i]);
            maxsofar=max(maxhere,maxsofar);
            maxprehere=maxhere;
            minprehere=minhere;
        }
        return maxsofar;
    }
};
