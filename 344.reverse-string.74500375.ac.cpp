/*
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (60.10%)
 * Total Accepted:    223.6K
 * Total Submissions: 372.1K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and returns the string
 * reversed.
 * 
 * 
 * Example:
 * Given s = "hello", return "olleh".
 * 
 */
class Solution {
public:
    string reverseString(string s) {
        if(s.length()==0)
        {
            return s;
        }
        string k="";
        int i=s.length()-1;
        while(i>=0)
        {
            k=k+s[i--];
        }
        return k;
    }
};
