/*
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (26.57%)
 * Total Accepted:    147K
 * Total Submissions: 553.1K
 * Testcase Example:  '0'
 *
 * Description:
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
void support(vector<int> & res)
{
    if(res.size()<1)
    {
        return;
    }
    for(int i=2;i*i<res.size();i++)
    {
        if(res[i])
        for(int k=i*i;k<res.size();k=k+i)
            res[k]=0;
    }
}

class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)
        {
            return 0;
        }
        vector<int> res(n,1);
        support(res);
        return std::accumulate(res.begin(),res.end(),-2);
    }
};
