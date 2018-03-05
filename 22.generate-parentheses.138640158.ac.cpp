/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (47.56%)
 * Total Accepted:    196.6K
 * Total Submissions: 413.5K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    int helper(vector<string> &res,int max,int open,int close,string temp)
    {
        if(temp.length()==2*max)
        {
            res.push_back(temp);
            return 0;
        }
        if(open<max)
        {
            helper(res,max,open+1,close,temp+"(");
        }
        if(close<open)
        {
            helper(res,max,open,close+1,temp+")");
        }
        return 1;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res,n,0,0,"");
        return res;
    }
};
