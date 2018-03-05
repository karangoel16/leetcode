/*
 * [172] Factorial Trailing Zeroes
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (36.85%)
 * Total Accepted:    112K
 * Total Submissions: 303.8K
 * Testcase Example:  '0'
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Note: Your solution should be in logarithmic time complexity.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int sum=0;
        while(n!=0)
        {
            sum+=(n/5);
            n=n/5;
        }
        return sum;
    }
};
