/*
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (15.65%)
 * Total Accepted:    189.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '""'
 *
 * 
 * Given an input string, reverse the string word by word.
 * 
 * 
 * 
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 * 
 * 
 * 
 * Update (2015-02-12):
 * For C programmers: Try to solve it in-place in O(1) space.
 * 
 * 
 * click to show clarification.
 * 
 * Clarification:
 * 
 * 
 * 
 * What constitutes a word?
 * A sequence of non-space characters constitutes a word.
 * Could the input string contain leading or trailing spaces?
 * Yes. However, your reversed string should not contain leading or trailing
 * spaces.
 * How about multiple spaces between two words?
 * Reduce them to a single space in the reversed string.
 * 
 * 
 * 
 */
class Solution {
public:
    void reverseWords(string &s) {
        int i=0;
        while(i<s.length() && s[i]==' ')
        {
            s.erase(s.begin()+i);
        }
        std::reverse(s.begin(),s.end());
        while(i<s.length() && s[i]==' ')
        {
            s.erase(s.begin()+i);
        }
        int flag=0;
        for(;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                int j=i+1;
                while(j<s.length() && s[j]==' ')
                {
                    s.erase(s.begin()+j);
                }
                std::reverse(s.begin()+flag,s.begin()+i);
                flag=i+1;
            }
        }
        std::reverse(s.begin()+flag,s.end());
    }
};
