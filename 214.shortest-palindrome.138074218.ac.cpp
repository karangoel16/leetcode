/*
 * [214] Shortest Palindrome
 *
 * https://leetcode.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (25.07%)
 * Total Accepted:    50.8K
 * Total Submissions: 202.7K
 * Testcase Example:  '"aacecaaa"'
 *
 * 
 * Given a string S, you are allowed to convert it to a palindrome by adding
 * characters in front of it. Find and return the shortest palindrome you can
 * find by performing this transformation.
 * 
 * 
 * For example: 
 * Given "aacecaaa", return "aaacecaaa".
 * Given "abcd", return "dcbabcd".
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases. Thanks to @Freezen for additional test cases.
 */
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.length()<=1)
            return s;
        int i=1,len=0;
        string test=s;
        std::reverse(test.begin(),test.end());
        test=s+"*"+test;
        vector<int> res(test.length(),0);
        while(i<test.length())
        {
            if(test[i]==test[len])
            {
                len++;
                res[i]=len;
                i++;
            }
            else
            {
                if(len==0){
                    res[i]=0;
                    i++;
                }
                else{
                    len=res[len-1];
                }
            }
        }
        test=s.substr(res.back());
        std::reverse(test.begin(),test.end());
        return test+s;
    }
};
