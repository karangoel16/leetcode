/*
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (43.95%)
 * Total Accepted:    25.9K
 * Total Submissions: 58.8K
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 * 
 * Example 1:
 * 
 * Input: 100
 * Output: "202"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -7
 * Output: "-10"
 * 
 * 
 * 
 * Note:
 * The input will be in range of [-1e7, 1e7].
 * 
 */
class Solution {
public:
    string convertToBase7(int num) {
        if(num==0)
        {
            return "0";
        }
        string test="";
        int flag=0;
        if(num<0)
        {
            num=-num;
            flag=1;
        }
        while(num)
        {
            test=to_string(num%7)+test;
            num=num/7;
        }
        if(flag)
        {
            return '-'+test;
        }
        return test;
    }
};
