/*
 * [357] Count Numbers with Unique Digits
 *
 * https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 *
 * algorithms
 * Medium (46.12%)
 * Total Accepted:    44.7K
 * Total Submissions: 97K
 * Testcase Example:  '2'
 *
 * Given a non-negative integer n, count all numbers with unique digits, x,
 * where 0 ≤ x < 10n.
 * 
 * 
 * ⁠   Example:
 * Given n = 2, return 91. (The answer should be the total numbers in the range
 * of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
 * 
 * 
 * Credits:Special thanks to @memoryless for adding this problem and creating
 * all test cases.
 */
class Solution {
   
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        
        if(n==0)
        {
            return 1;
        }
        vector <int> temp;
        temp.push_back(10);
        temp.push_back(81);
        int i=temp.size();
        int k=8;
        while(i<n)
        {
            temp.push_back(temp[i-1]*k);
            k--;
            i++;
        }
        return std::accumulate(temp.begin(),temp.begin()+n,0);
    }
};
