/*
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (26.03%)
 * Total Accepted:    200.1K
 * Total Submissions: 768.6K
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n).
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 */
double helper(double x,long n)
{
        if(n==0)
        {
            return 1;
        }
        if(n<0)
        {
            x=1/x;
            n=-1*n;
        }
        double temp=helper(x,n/2);
        if(n%2==0)
        {
            return temp*temp;
        }
        else
        {
            return temp*temp*x;
        }
        return 0;
}
class Solution {
public:
    double myPow(double x, int n) {
        return helper(x,n);
    }
};
