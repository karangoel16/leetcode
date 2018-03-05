/*
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (39.07%)
 * Total Accepted:    102K
 * Total Submissions: 261.2K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * 
 * Example 1:
 * Given s = "hello", return "holle".
 * 
 * 
 * 
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 * 
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 */
class Solution {
public:
    string reverseVowels(string s) {
        int i=0;
        vector <int> it;
        while(i<s.length())
        {
            switch(s[i])
            {
                case 'a':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                case 'e':
                case 'i':
                case 'o':
                case 'u':it.push_back(i);
                         break;
            }
            i++;
        }
        i=0;
        while(i<(it.size()/2))
        {
            char temp=s[it[i]];
            s[it[i]]=s[it[it.size()-1-i]];
            s[it[it.size()-1-i]]=temp;
            i++;
            
        }
        return s;
    }
};
