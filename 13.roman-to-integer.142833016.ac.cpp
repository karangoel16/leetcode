/*
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (47.73%)
 * Total Accepted:    213.1K
 * Total Submissions: 446.4K
 * Testcase Example:  '"DCXXI"'
 *
 * Given a roman numeral, convert it to an integer.
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
public:
    int romanToInt(string s) {
            unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
            int sum=T[s.back()];
            for(int i=s.length()-2;i>=0;i--)
            {
                if(T[s[i]]<T[s[i+1]]){
                    sum-=T[s[i]];
                }
                else
                    sum+=T[s[i]];
            }
        return sum;
    }
};
