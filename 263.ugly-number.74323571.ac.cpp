/*
 * [263] Ugly Number
 *
 * https://leetcode.com/problems/ugly-number/description/
 *
 * algorithms
 * Easy (39.62%)
 * Total Accepted:    118.9K
 * Total Submissions: 300.2K
 * Testcase Example:  '-2147483648'
 *
 * 
 * Write a program to check whether a given number is an ugly number.
 * 
 * 
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 6, 8 are ugly while 14 is not ugly since it includes another
 * prime factor 7.
 * 
 * 
 * 
 * Note that 1 is typically treated as an ugly number.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    bool isUgly(int num) {
        int flag=1;
        if(num<1)
            return false;
        if(num==1)
        {
            return true;
        }
        while(num!=1)
        {
            if(num%2==0)
            {
                num=num/2;
                continue;
            }
            else if(num%3==0)
            {
                num=num/3;
                continue;
            }
            else if(num%5==0)
            {
                num=num/5;
                continue;
            }
            else if(num)
            {
                return false;
            }
        }
        return true;
    }
};
