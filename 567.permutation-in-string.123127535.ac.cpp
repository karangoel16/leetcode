/*
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (36.42%)
 * Total Accepted:    18.9K
 * Total Submissions: 51.8K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's
 * permutations is the substring of the second string.
 * 
 * Example 1:
 * 
 * Input:s1 = "ab" s2 = "eidbaooo"
 * Output:True
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 * 
 * 
 * 
 * Note:
 * 
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 * 
 * 
 */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
        {
            return false;
        }
        vector<int> count(26,0);
        for(int i=0;i<s1.length();i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        if(allzeros(count))
        {
            return true;
        }
        for(int i=s1.length();i<s2.length();i++)
        {
            count[s2[i]-'a']--;
            count[s2[i-s1.length()]-'a']++;
            if(allzeros(count))
            {
                return true;
            }
        }
        return false;
    }
    bool allzeros(vector<int> num)
    {
        for(auto i:num)
        {
            if(i!=0)
            {
                return false;
            }
        }
        return true;
    }
};
