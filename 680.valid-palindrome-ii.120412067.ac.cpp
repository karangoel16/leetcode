/*
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (32.38%)
 * Total Accepted:    22.9K
 * Total Submissions: 70.7K
 * Testcase Example:  '"aba"'
 *
 * 
 * Given a non-empty string s, you may delete at most one character.  Judge
 * whether you can make it a palindrome.
 * 
 * 
 * Example 1:
 * 
 * Input: "aba"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 * 
 * 
 * 
 * Note:
 * 
 * The string will only contain lowercase characters a-z.
 * The maximum length of the string is 50000.
 * 
 * 
 */
class Solution {
public:
    bool isPallidrome(string s)
    {
        string t=s;
        std::reverse(t.begin(),t.end());
        return t==s;
    }
    bool validPalindrome(string s) {
        for(int i=0,j=s.length()-1;i<j;i++,j--)
        {
            if(s[i]==s[j])
            {
                continue;
            }
            else
            {
                //std::cout<<s.substr(i+1,j-i)<<"\t"<<s.substr(i,j-i)<<"\n";
                return isPallidrome(s.substr(i+1,j-i))||isPallidrome(s.substr(i,j-i));
            }
        }
        return true;
    }
};
