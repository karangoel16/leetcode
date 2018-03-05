/*
 * [313] Super Ugly Number
 *
 * https://leetcode.com/problems/super-ugly-number/description/
 *
 * algorithms
 * Medium (38.30%)
 * Total Accepted:    44.7K
 * Total Submissions: 116.6K
 * Testcase Example:  '1\n[2,3,5]'
 *
 * 
 * ⁠   Write a program to find the nth super ugly number.
 * 
 * 
 * 
 * ⁠   Super ugly numbers are positive numbers whose all prime factors are in
 * the given prime list
 * ⁠   primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28,
 * 32]
 * ⁠is the sequence of the first 12 super ugly numbers given primes
 * ⁠   = [2, 7, 13, 19] of size 4.
 * 
 * 
 * 
 * ⁠   Note:
 * ⁠   (1) 1 is a super ugly number for any given primes.
 * ⁠   (2) The given numbers in primes are in ascending order.
 * ⁠   (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 * ⁠   (4) The nth super ugly number is guaranteed to fit in a 32-bit signed
 * integer.
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
       if(n<=0)return 0;
       if(n==1)return 1;
       vector<int> res(n,0);
       vector<int> helper(primes.size(),0);
       res[0]=1;//intial value
       for(int i=1;i<n;i++)
       {
           int min=INT_MAX;
           for(int i=0;i<primes.size();i++)
           {
                if(min>(primes[i]*res[helper[i]]))
                {
                    min=primes[i]*res[helper[i]];
                }
           }
           res[i]=min;
           for(int k=0;k<primes.size();k++)
           {
               if(res[i]==primes[k]*res[helper[k]])
               {
                   helper[k]++;
               }
           }
       }
       //for(auto i:res)
       //{
       //       std::cout<<i<<"\n";
       //}
       return res[n-1];
    }
};
