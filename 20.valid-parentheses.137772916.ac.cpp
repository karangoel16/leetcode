/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (33.94%)
 * Total Accepted:    305.5K
 * Total Submissions: 900K
 * Testcase Example:  '"["'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s)
        {
            switch(c)
            {
                case '{':
                case '(':
                case '[':
                    st.push(c);
                    break;
                case '}':
                    if(!st.empty() && st.top()=='{')
                    {
                        st.pop();
                        break;
                    }    
                    else
                        return false;
                case ']':
                    if(!st.empty() && st.top()=='[')
                    {
                        st.pop();
                        break;
                    }  
                    else
                        return false;
                case ')':
                    if(!st.empty() && st.top()=='(')
                    {
                        st.pop();
                        break;
                    }      
                    else 
                        return false;
                default:;
            }
        }
        return st.empty();
    }
};
