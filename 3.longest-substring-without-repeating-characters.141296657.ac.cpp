/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.64%)
 * Total Accepted:    444.8K
 * Total Submissions: 1.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> len;
        int val=0;
        for(int i=0,j=0;i<s.length();i++)
        {
            if(len.find(s[i])!=len.end())
                j=max(j,len[s[i]]+1);
            len[s[i]]=i;
            val=max(val,i-j+1);
        }
        return val;
    }
};
