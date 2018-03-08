/*
 * [190] Reverse Bits
 *
 * https://leetcode.com/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (29.40%)
 * Total Accepted:    127.5K
 * Total Submissions: 433.5K
 * Testcase Example:  '           0 (00000000000000000000000000000000)'
 *
 * Reverse bits of a given 32 bits unsigned integer.
 * 
 * For example, given input 43261596 (represented in binary as
 * 00000010100101000001111010011100), return 964176192 (represented in binary
 * as 00111001011110000010100101000000).
 * 
 * 
 * Follow up:
 * If this function is called many times, how would you optimize it?
 * 
 * 
 * Related problem: Reverse Integer
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t temp=0;
        int i=1;
        while(n){
            temp=temp|((1&n)<<(32-i));
            n>>=1;
            i++;
        }
        return temp;
    }
};
