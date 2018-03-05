/*
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (29.02%)
 * Total Accepted:    142.8K
 * Total Submissions: 492.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * 
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(!nums.size() || nums.size()==1)
        {
            return ;
        }
        int j=-1;
        for (int i = nums.size() - 2; i >= 0; i--) 
        {
            if(nums[i]<nums[i+1])
            {
                j=i;
                break;
            }
        }
        if(j==-1)
        {
            std::reverse(nums.begin(),nums.end());
            return;
        }
        int l=-1;
        for(int i=nums.size()-1;i>j;i--)
        {
            if(nums[i]>nums[j])
            {
                l=i;
                break;
            }
        }
        swap(nums[l],nums[j]);
        std::reverse(nums.begin()+j+1,nums.end());
    }
};
