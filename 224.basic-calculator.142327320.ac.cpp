/*
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (28.45%)
 * Total Accepted:    63K
 * Total Submissions: 221.5K
 * Testcase Example:  '"1 + 1"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string may contain open ( and closing parentheses ), the plus
 * + or minus sign -, non-negative integers and empty spaces  .
 * 
 * You may assume that the given expression is always valid.
 * 
 * Some examples:
 * 
 * "1 + 1" = 2
 * " 2-1 + 2 " = 3
 * "(1+(4+5+2)-3)+(6+8)" = 23
 * 
 * 
 * 
 * 
 * Note: Do not use the eval built-in library function.
 * 
 */
class Solution {
public:
    int helper(string &s,int low,int high){
        if(low>=high)
            return 0;
        stack<int> st;
        stack<int> opr;
        int res=0;
        int prev=0;
        int op=1;
        for(int i=low;i<high;){
            
            switch(s[i]){
                    case')':
                            //std::cout<<res<<"\n";
                            res=st.top()+opr.top()*(res+op*prev);
                            opr.pop();
                            st.pop();
                            prev=0;
                            op=1;
                            i++;
                            break;
                    case '(':
                            st.push(res);
                            opr.push(op);
                            op=1;
                            res=0;
                            prev=0;
                            i++;
                            break;
                    case '+':
                    case '-':
                            res+=op*prev;
                            //std::cout<<res<<"**\n";
                            prev=0;
                            op=s[i]=='+'?1:-1;
                            i++;
                            break;
                    case ' ':i++;break;
                default:
                            while(i<high && isdigit(s[i])){
                                prev=10*prev+(s[i++]-'0');
                            }
                        
            }
        }
        res+=op*prev;
        //std::cout<<res<<"\n";
        return res;
    }
    int calculate(string s) {
        return helper(s,0,s.length());
    }
};
