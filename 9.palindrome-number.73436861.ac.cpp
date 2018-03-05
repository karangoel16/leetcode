/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (35.68%)
 * Total Accepted:    303.5K
 * Total Submissions: 850.5K
 * Testcase Example:  '-2147483648'
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * click to show spoilers.
 * 
 * Some hints:
 * 
 * Could negative integers be palindromes? (ie, -1)
 * 
 * If you are thinking of converting the integer to string, note the
 * restriction of using extra space.
 * 
 * You could also try reversing an integer. However, if you have solved the
 * problem "Reverse Integer", you know that the reversed integer might
 * overflow. How would you handle such case?
 * 
 * There is a more generic way of solving this problem.
 * 
 * 
 */
class Solution {
public:
    bool isPalindrome(int x) {
        string s=std::to_string(x);
        //std::cout<<s.length();
        const char *p=s.c_str();
        int i=0;
        if(p[i]=='-')
        {/*
            i=1;
            while(i<(s.length()+1)/2)
            {
                if(p[i]!=p[s.length()-i])
                {
                    return false;
                }
                i++;
            }*/
            return false;
        }
        else
        {
            while(i<s.length()/2)
            {
                if(p[i]!=p[s.length()-1-i])
                {
                    return false;
                }
                i++;
            }
            return true;
        }
    }
};
