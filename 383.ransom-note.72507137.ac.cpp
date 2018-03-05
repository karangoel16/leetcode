/*
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (47.68%)
 * Total Accepted:    74.7K
 * Total Submissions: 156.6K
 * Testcase Example:  '"a"\n"b"'
 *
 * 
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the
 * ransom 
 * note can be constructed from the magazines ; otherwise, it will return
 * false. 
 * 
 * 
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 * 
 * 
 * Note:
 * You may assume that both strings contain only lowercase letters.
 * 
 * 
 * 
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 * 
 * 
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ran[26],mag[26];
        int i=0;
        int j;
        while(i<26)
        {
            ran[i]=mag[i]=0;
            i++;
        }
        i=0;
        while(i<ransomNote.length())
        {
            j=ransomNote[i++]-97;
            ran[j]++;
        }
        i=0;
        while(i<magazine.length())
        {
            j=magazine[i++]-97;
            mag[j]++;
        }
        i=0;
        bool flag=true;
        while(i<26)
        {
            if(mag[i]<ran[i])
            {
                flag=false;
                return flag;
            }
            i++;
        }
        return flag;
    }
};
