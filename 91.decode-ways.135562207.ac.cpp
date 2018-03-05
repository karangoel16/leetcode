/*
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (20.26%)
 * Total Accepted:    162.6K
 * Total Submissions: 802.6K
 * Testcase Example:  '""'
 *
 * 
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 
 * Given an encoded message containing digits, determine the total number of
 * ways to decode it.
 * 
 * 
 * 
 * For example,
 * Given encoded message "12",
 * it could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * 
 * The number of ways decoding "12" is 2.
 * 
 */
class Solution {
public:
    int numDecodings(string s) {
       if(!s.length()|| s[0]=='0')
       {
           return 0;
       }
       vector<int> dp(s.length()+1,0);
       dp[0]=1;
       for(int i=1;i<=s.length();i++)
       {
           if(i>1)
           {
               int temp=10*(s[i-2]-'0')+(s[i-1]-'0');
               if(temp%10!=0 && temp>10 && temp<=26) 
                   dp[i]=dp[i-1]+dp[i-2];
               else if(temp==10 || temp==20)
                   dp[i]=dp[i-2];
               else if(temp<=0 || (temp>=30 && s[i-1]=='0'))
                   return 0;
               else
                   dp[i]=dp[i-1];
           }
           else
           {
               dp[i]=dp[i-1];
           }
           //std::cout<<dp[i]<<"\t";
       }
       return dp[s.length()];
    }
};
