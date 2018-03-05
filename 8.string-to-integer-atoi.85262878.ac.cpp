/*
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (13.99%)
 * Total Accepted:    216.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '""'
 *
 * Implement atoi to convert a string to an integer.
 * 
 * Hint: Carefully consider all possible input cases. If you want a challenge,
 * please do not see below and ask yourself what are the possible input cases.
 * 
 * Notes: It is intended for this problem to be specified vaguely (ie, no given
 * input specs). You are responsible to gather all the input requirements up
 * front.
 * 
 * 
 * 
 * Requirements for atoi:
 * 
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned. If the
 * correct value is out of the range of representable values, INT_MAX
 * (2147483647) or INT_MIN (-2147483648) is returned.
 * 
 */
class Solution {
public:
    int myAtoi(string str) {
        long int res=0;
        int flag=1;
        if(str.length()==0)
        {
            return res;
        }
        int i=0;
        while(str[i]==' ')
        {
            i++;
        }
        if(str[i]=='+')
        {
            flag=1;
            i++;
        }
        else if(str[i]=='-')
        {
            flag=-1;
            i++;
        }
        if(!isdigit(str[i]))
        {
            return res;
        }
        for(;i<str.length();i++)
        {
            if(isdigit(str[i]))
            {
                res=10*res+((int)str[i]-48);
            }
            else
            {
                return flag*res;
            }
            if(flag*res<INT_MIN)
            {
                return INT_MIN;
            }
            if(flag*res>INT_MAX)
            {
                return INT_MAX;
            }
        }
        return flag*res;
    }
};
