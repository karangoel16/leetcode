/*
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (26.64%)
 * Total Accepted:    138.9K
 * Total Submissions: 521.4K
 * Testcase Example:  '"a"\n"a"'
 *
 * 
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * 
 * 
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * 
 * 
 * Minimum window is "BANC".
 * 
 * 
 * 
 * Note:
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * 
 * 
 * If there are multiple such windows, you are guaranteed that there will
 * always be only one unique minimum window in S.
 * 
 */
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length() || s.length()==0)
        {
            return "";
        }
        unordered_map<char,int> mp;
        for(auto i:t)
            mp[i]++;
        int left=0,minLeft=0,minLength=INT_MAX,count=0;
        for(int right=0;right<s.length();right++)
        {
            if(--mp[s[right]]>=0)
                count++;
            while(count==t.length())
            {
                if(right-left+1<minLength)
                {
                    minLeft=left;
                    minLength=right-left+1;
                }
                if(++mp[s[left]]>0)
                {
                    count--;
                }
                left++;
            }
        }
        if(s.length()<minLength)
        {
            return "";
        }
        return s.substr(minLeft,minLength);
    }
};
