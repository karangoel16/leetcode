/*
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (42.69%)
 * Total Accepted:    17.4K
 * Total Submissions: 40.8K
 * Testcase Example:  '"ABAB"\n2'
 *
 * Given a string that consists of only uppercase English letters, you can
 * replace any letter in the string with another letter at most k times. Find
 * the length of a longest substring containing all repeating letters you can
 * get after performing the above operations.
 * 
 * Note:
 * Both the string's length and k will not exceed 104.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * s = "ABAB", k = 2
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * Replace the two 'A's with two 'B's or vice versa.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s = "AABABBA", k = 1
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 * 
 * 
 */
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> pos(26,0);
        int left=0;
        int maxCount=0;
        int maxLength=0;
        for(int right=0;right<s.length();right++)
        {
            pos[s[right]-'A']++;
            maxCount=*std::max_element(pos.begin(),pos.end());
            while(right-left+1-maxCount>k)
                pos[s[left++]-'A']--;
            maxLength=std::max(maxLength,right-left+1);
        }
        return maxLength;
    }
};
