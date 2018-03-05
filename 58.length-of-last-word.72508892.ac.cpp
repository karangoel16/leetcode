/*
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.06%)
 * Total Accepted:    181.3K
 * Total Submissions: 565.6K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length()==0)
        {
            return 0;
        }
        //const char * ch = s.c_str();
        while(s[s.length()-1]==' ')
        {
           s.resize(s.length()-1);
        }
        int i=0;
        int flag=0;
        int temp=0;
        while(i<s.length())
        {
            if(s[i]==' ')
            {
                flag=1;
                temp=i;
            }
            i++;
        }
        if(!flag)
        {
            return s.length();
        }
        else
        {
            return s.length()-1-temp;
        }
    }
};
