/*
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (28.26%)
 * Total Accepted:    111.1K
 * Total Submissions: 393.2K
 * Testcase Example:  '["18"]'
 *
 * 
 * Evaluate the value of an arithmetic expression in Reverse Polish
 * Notation.
 * 
 * 
 * 
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 * 
 * 
 * 
 * Some examples:
 * 
 * ⁠ ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ⁠ ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 * 
 * 
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto i:tokens)
        {
            try{
                int temp=stoi(i);
                st.push(temp);
            }catch(const std::exception& e){
                    int temp=st.top();st.pop();
                    int temp2=st.top();st.pop();
                    int temp3=0;
                    if(i=="+")
                        temp3=temp2+temp;
                    else if(i=="-")
                        temp3=temp2-temp;
                    else if(i=="/")
                        temp3=temp2/temp;
                    else
                        temp3=temp2*(temp);
                    st.push(temp3);
                }
        }
        return st.top();
    }
};
