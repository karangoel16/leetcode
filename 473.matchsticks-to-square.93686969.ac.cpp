/*
 * [473] Matchsticks to Square
 *
 * https://leetcode.com/problems/matchsticks-to-square/description/
 *
 * algorithms
 * Medium (35.35%)
 * Total Accepted:    14.6K
 * Total Submissions: 41.4K
 * Testcase Example:  '[1,1,2,2,2]'
 *
 * Remember the story of Little Match Girl? By now, you know exactly what
 * matchsticks the little match girl has, please find out a way you can make
 * one square by using up all those matchsticks. You should not break any
 * stick, but you can link them up, and each matchstick must be used exactly
 * one time.
 * 
 * ⁠Your input will be several matchsticks the girl has, represented with their
 * stick length. Your output will either be true or false, to represent whether
 * you could make one square using all the matchsticks the little match girl
 * has.
 * 
 * Example 1:
 * 
 * Input: [1,1,2,2,2]
 * Output: true
 * 
 * Explanation: You can form a square with length 2, one side of the square
 * came two sticks with length 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [3,3,3,3,4]
 * Output: false
 * 
 * Explanation: You cannot find a way to form a square with all the
 * matchsticks.
 * 
 * 
 * 
 * Note:
 * 
 * The length sum of the given matchsticks is in the range of 0 to 10^9.
 * The length of the given matchstick array will not exceed 15.
 * 
 * 
 */
bool helper(vector<int> nums,int size,int sum1,int sum2,int sum3,int sum4,int width)
{
    if(sum1>width||sum2>width||sum3>width||sum4>width)
    {
        return false;
    }
    if(size==-1)
    {
        if(sum1==width && sum2==width && sum3==width && sum4==width)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return helper(nums,size-1,sum1+nums[size],sum2,sum3,sum4,width)||helper(nums,size-1,sum1,sum2+nums[size],sum3,sum4,width)||helper(nums,size-1,sum1,sum2,sum3+nums[size],sum4,width)+helper(nums,size-1,sum1,sum2,sum3,sum4+nums[size],width);
    
}
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        long sum=std::accumulate(nums.begin(),nums.end(),0);
        if(sum%4!=0 || nums.size()<4) 
        {
            return false;
        }
        int width=(sum)/4;
        int sum1=0,sum2=0,sum3=0,sum4=0;
        std::sort(nums.begin(),nums.end());
        return helper(nums,nums.size()-1,sum1,sum2,sum3,sum4,width);
    }
};
