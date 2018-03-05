/*
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (41.73%)
 * Total Accepted:    52.6K
 * Total Submissions: 126.1K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry=0;
        if(num1.length() < num2.length())
        {
            std::swap(num1,num2);
        }
        stringstream ss;
        std::reverse(num1.begin(),num1.end());
        std::reverse(num2.begin(),num2.end());
        for(int i=0;i<num2.length();i++)
        {
            int temp=num1[i]-48+num2[i]-48+carry;
            carry=(temp/10);
            temp%=10;
            //std::cout<<temp<<"\n";
            ss<<temp;
        }
        for(int i=num2.length();i<num1.length();i++)
        {
            int temp=num1[i]-48+carry;
            carry=(temp/10);
            temp%=10;
            ss<<temp;
        }
        if(carry)
        {
            ss<<carry;
        }
        string temp=ss.str();
        std::reverse(temp.begin(),temp.end());
        return temp;
    }
};
