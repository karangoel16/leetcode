/*
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (43.82%)
 * Total Accepted:    34.2K
 * Total Submissions: 78K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string. If there are
 * less than k characters left, reverse all of them. If there are less than 2k
 * but greater than or equal to k characters, then reverse the first k
 * characters and left the other as original.
 * 
 * 
 * Example:
 * 
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * 
 * 
 * 
 * Restrictions: 
 * 
 * ⁠The string consists of lower English letters only.
 * ⁠Length of the given string and k will in the range [1, 10000]
 * 
 */
class Solution {
public:
    string reverse(string s)
    {
        string val="";
        for(int i=s.length()-1;i>=0;i--)
        {
            val+=s[i];
        }
        return val;
    }
    string reverseStr(string s, int k) {
        if(s.length()<k)
        {
            return reverse(s);
        }
        bool flag=true;
        string res="";
        for(int i=0;i<s.length();i+=k)
        {
            res+=flag?reverse(s.substr(i,k)):s.substr(i,k);
            flag=!flag;
        }
        return res;
    }
};
