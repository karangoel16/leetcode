/*
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (40.63%)
 * Total Accepted:    119.4K
 * Total Submissions: 293.9K
 * Testcase Example:  '27'
 *
 * 
 * ⁠   Given an integer, write a function to determine if it is a power of
 * three.
 * 
 * 
 * ⁠   Follow up:
 * ⁠   Could you do it without using any loop / recursion?
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int max=1162261467;
    bool isPowerOfThree(int n) {
        if(n<=0 || n>max) return false;
        return (max%n)==0;
    }
};
