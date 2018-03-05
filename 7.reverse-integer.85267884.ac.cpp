/*
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (24.39%)
 * Total Accepted:    371.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * Input: 123
 * Output:  321
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only hold integers
 * within the 32-bit signed integer range. For the purpose of this problem,
 * assume that your function returns 0 when the reversed integer overflows.
 * 
 */
class Solution {
public:
    int reverse(int x) {
        int flag=1;
        if(x<0)
        {
            flag=-1;
            x=-x;
        }
        long res=0;
        while(x)
        {
            res=10*res+(x%10);
            x=x/10;
            if(res*flag>INT_MAX)
            {
                return 0;
            }
            if(res*flag<INT_MIN)
            {
                return 0;
            }
        }
        return flag*res;
    }
};
