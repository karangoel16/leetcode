/*
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (46.48%)
 * Total Accepted:    54.4K
 * Total Submissions: 117K
 * Testcase Example:  '2'
 *
 * 
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * 
 * 
 * For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10
 * = 3 + 3 + 4).
 * 
 * 
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    int integerBreak(int n) {
        if(n<=2)
        {
            return 1;
        }
        vector<int> prod(n+1,0);
        prod[0]=1;
        prod[1]=1;
        prod[2]=1;
        //std::cout<<"*\n";
        for(int i=3;i<=n;i++)
        {
            int mx=0;
            for(int j=2;j<i;j++)
            {
                mx=max(max(mx,j*(i-j)),prod[j]*(i-j));
            }
            prod[i]=mx;
        }
        return prod[n];
    }
};
