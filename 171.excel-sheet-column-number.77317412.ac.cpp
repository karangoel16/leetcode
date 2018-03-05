/*
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (48.30%)
 * Total Accepted:    159.9K
 * Total Submissions: 331K
 * Testcase Example:  '"A"'
 *
 * Related to question Excel Sheet Column Title
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 * 
 * For example:
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    int titleToNumber(string s) {
        int i=s.length()-1;
        int j=0;
        int sum=0;
        while(i>=0)
        {
            sum+=pow(26,j)*((int)s[i]-64);
            //std::cout<<sum<<std::endl;
            --i;
            ++j;
        }
        return sum;
    }
};
