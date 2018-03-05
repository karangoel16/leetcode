/*
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (33.27%)
 * Total Accepted:    71.7K
 * Total Submissions: 215.5K
 * Testcase Example:  '1'
 *
 * 
 * Write a program to find the n-th ugly number.
 * 
 * 
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * 
 * 
 * Note that 1 is typically treated as an ugly number, and n does not exceed
 * 1690.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=0)return 0;
        if(n==1)return 1;
        int t=0;
        int j=0;
        int k=0;
        vector<int> res(n,0);
        res[0]=1;
        for(int i=1;i<n;i++)
        {
            res[i]=min(res[t]*2,min(res[j]*3,res[k]*5));
            if(res[i]==res[t]*2)t++;
            if(res[i]==res[j]*3)j++;
            if(res[i]==res[k]*5)k++;
        }
        return res[n-1];
    }
};
