/*
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (38.16%)
 * Total Accepted:    48.6K
 * Total Submissions: 127.4K
 * Testcase Example:  '"abab"'
 *
 * Given a non-empty string check if it can be constructed by taking a
 * substring of it and appending multiple copies of the substring together.
 * You may assume the given string consists of lowercase English letters only
 * and its length  will not exceed 10000. 
 * 
 * Example 1:
 * 
 * Input: "abab"
 * 
 * Output: True
 * 
 * Explanation: It's the substring "ab" twice.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "aba"
 * 
 * Output: False
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: "abcabcabcabc"
 * 
 * Output: True
 * 
 * Explanation: It's the substring "abc" four times. (And the substring
 * "abcabc" twice.)
 * 
 * 
 */
bool helper(string s)
{
    if(s.length()==0)
    {
        return false;
    }
    for(int i=1;i<=s.length()/2;i++)
    {
        string temp=s.substr(0,i);
        string temp2;
        for(int j=0;j<(s.length())/i;j++)
        {
            temp2+=temp;
        }
        //std::cout<<temp2<<"\n";
        if(temp2==s)
        {
            return true;
        }
    }
    return false;
}
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        return helper(str);
    }
};
