/*
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (47.31%)
 * Total Accepted:    201.1K
 * Total Submissions: 425.1K
 * Testcase Example:  '""\n""'
 *
 * Given two strings s and t, write a function to determine if t is an anagram
 * of s. 
 * 
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()==0 && t.length()==0)
        {
            return true;
        }
        int temp[26],temp2[26];
        int i=0;
        while(i<26)
        {
            temp[i]=0;
            temp[i++]=0;
        }
        std::sort(s.begin(),s.end());
        std::sort(t.begin(),t.end());
        if(s.length()!=t.length())
        {
            return false;
        }
        i=0;
        while(i<s.length())
        {
            if(s[i]!=t[i])
            {
                return false;
            }
            i++;
        }
        std::cout<<s;
        return true;
    }
};
