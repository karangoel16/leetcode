/*
 * [556] Next Greater Element III
 *
 * https://leetcode.com/problems/next-greater-element-iii/description/
 *
 * algorithms
 * Medium (29.02%)
 * Total Accepted:    12.2K
 * Total Submissions: 41.9K
 * Testcase Example:  '12'
 *
 * Given a positive 32-bit integer n, you need to find the smallest 32-bit
 * integer which has exactly the same digits existing in the integer n and is
 * greater in value than n. If no such positive 32-bit integer exists, you need
 * to return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: 12
 * Output: 21
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 21
 * Output: -1
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int nextGreaterElement(int n) {
        auto digit = to_string(n);
        next_permutation(digit.begin(),digit.end());
        long temp = stol(digit);
        return temp>INT_MAX || temp<=n?-1:temp;
    }
};
