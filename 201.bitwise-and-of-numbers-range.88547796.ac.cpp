/*
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (34.38%)
 * Total Accepted:    63.6K
 * Total Submissions: 185K
 * Testcase Example:  '0\n0'
 *
 * Given a range [m, n] where 0 
 * 
 * 
 * For example, given the range [5, 7], you should return 4.
 * 
 * 
 * Credits:Special thanks to @amrsaqr for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return (n>m)?(rangeBitwiseAnd(m/2,n/2)<<1):m;
    }
};
