/*
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (40.65%)
 * Total Accepted:    164.3K
 * Total Submissions: 404.1K
 * Testcase Example:  '1'
 *
 * 
 * Given an integer, write a function to determine if it is a power of two.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int max=1073741824;
    bool isPowerOfTwo(int n) {
        if(n<=0 || n>max) return false;
        return (max%n)==0;
    }
};
