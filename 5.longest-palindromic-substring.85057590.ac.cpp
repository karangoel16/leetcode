/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.18%)
 * Total Accepted:    290.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example:
 * 
 * 
 * Input: "babad"
 * 
 * Output: "bab"
 * 
 * Note: "aba" is also a valid answer.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "cbbd"
 * 
 * Output: "bb"
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
            int len=s.length();
    int i=0;
    int high;
    int low;
    int start=0;
    int maxlength=1;
    while(i<s.length())
    {
        high=i;
        low=i-1;//this is for even pallindrome
        while(low>=0 && high<len && s[high]==s[low])
        {
            if(high-low+1>maxlength)
            {
                maxlength=(high-low+1);
                start=low;
            }
            high++;
            low--;
        }
        high=i+1;
        low=i-1;//this is for odd integer
        while(low>=0 && high<len && s[high]==s[low])
        {
            if(high-low+1>maxlength)
            {
                maxlength=(high-low+1);
                start=low;
            }
            high++;
            low--;
        }
        i++;
    }
    //std::cout<<s.substr(start,maxlength);
    return s.substr(start,maxlength);
        //return s.substr(pos,size);
    }
};
