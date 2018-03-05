/*
 * [633] Sum of Square Numbers
 *
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Easy (32.34%)
 * Total Accepted:    20.6K
 * Total Submissions: 63.8K
 * Testcase Example:  '5'
 *
 * 
 * Given a non-negative integer c, your task is to decide whether there're two
 * integers a and b such that a2 + b2 = c.
 * 
 * 
 * Example 1:
 * 
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 3
 * Output: False
 * 
 * 
 * 
 */
class Solution {
public:
    bool judgeSquareSum(int c) {
        int i=0,j=(int)sqrt(c);
        while(i<=j)
        {
            int res=i*i+j*j;
            if(res==c)
            {
                return true;
            }
            if(res<c)
            {
                i=i+1;
            }
            else
            {
                j=j-1;
            }
        }
        return false;
    }
};
